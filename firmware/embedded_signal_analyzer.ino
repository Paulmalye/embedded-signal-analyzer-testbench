#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <arduinoFFT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

TwoWire I2C_1 = TwoWire(0);
TwoWire I2C_2 = TwoWire(1);

Adafruit_SSD1306 oled1(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_1, -1);
Adafruit_SSD1306 oled2(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_2, -1);

// GPIO
const int POT_FREQ = 34;
const int POT_DUTY = 35;

const int PWM_OUT = 25;
const int LED_OUT = 26;

const int ADC_RC = 32;
const int FREQ_IN = 33;
const int FFT_IN = 39;   // SN sur ta carte ESP32

// PWM
const int PWM_RES = 8;

// ADC
const int SAMPLE_COUNT = 100;
float smoothVoltage = 0.0;
const float alpha = 0.10;

// FFT
const uint16_t SAMPLES = 512;
const double SAMPLING_FREQ = 20000.0;

double vReal[SAMPLES];
double vImag[SAMPLES];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, SAMPLES, SAMPLING_FREQ);

float measureFrequency()
{
  unsigned long highTime = pulseIn(FREQ_IN, HIGH, 100000);
  unsigned long lowTime  = pulseIn(FREQ_IN, LOW, 100000);

  if (highTime == 0 || lowTime == 0) return 0;

  float period = highTime + lowTime;
  return 1000000.0 / period;
}

double computeFFT()
{
  unsigned long samplingPeriodUs = 1000000.0 / SAMPLING_FREQ;
  unsigned long timer;

  for (int i = 0; i < SAMPLES; i++)
  {
    timer = micros();

    int adcRaw = analogRead(FFT_IN);
    vReal[i] = adcRaw;
    vImag[i] = 0;

    while (micros() - timer < samplingPeriodUs) {
      // wait
    }
  }

  FFT.windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(FFT_FORWARD);
  FFT.complexToMagnitude();

  return FFT.majorPeak();
}

void setup()
{
  Serial.begin(115200);

  I2C_1.begin(21, 22);
  I2C_2.begin(18, 19);

  if (!oled1.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED 1 ERROR");
    while (1);
  }

  if (!oled2.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED 2 ERROR");
    while (1);
  }

  oled1.clearDisplay();
  oled2.clearDisplay();

  oled1.setTextColor(SSD1306_WHITE);
  oled2.setTextColor(SSD1306_WHITE);

  pinMode(FREQ_IN, INPUT);

  ledcAttach(PWM_OUT, 1000, PWM_RES);
  ledcAttach(LED_OUT, 1000, PWM_RES);

  analogReadResolution(12);
}

void loop()
{
  int rawFreq = analogRead(POT_FREQ);
  int rawDuty = analogRead(POT_DUTY);

  int freq = map(rawFreq, 0, 4095, 200, 5000);
  int dutyPercent = map(rawDuty, 0, 4095, 10, 90);
  int dutyValue = map(dutyPercent, 0, 100, 0, 255);

  ledcChangeFrequency(PWM_OUT, freq, PWM_RES);
  ledcWrite(PWM_OUT, dutyValue);
  ledcWrite(LED_OUT, dutyValue);

  // ADC filtre RC
  float minV = 99.0;
  float maxV = 0.0;
  float sumV = 0.0;

  for (int i = 0; i < SAMPLE_COUNT; i++)
  {
    int adcRaw = analogRead(ADC_RC);
    float voltage = adcRaw * 3.3 / 4095.0;

    if (voltage < minV) minV = voltage;
    if (voltage > maxV) maxV = voltage;

    sumV += voltage;
    delayMicroseconds(500);
  }

  float avgV = sumV / SAMPLE_COUNT;
  float rangeV = maxV - minV;

  smoothVoltage = alpha * avgV + (1.0 - alpha) * smoothVoltage;

  // Frequence + FFT
  float measuredFreq = measureFrequency();
  double fftPeak = computeFFT();

  float freqError = 0.0;
  if (measuredFreq > 0)
  {
    freqError = abs(measuredFreq - freq) * 100.0 / freq;
  }

  float fftError = 0.0;
  if (fftPeak > 0)
  {
    fftError = abs(fftPeak - freq) * 100.0 / freq;
  }

  bool freqPass = measuredFreq > 0 && freqError < 5.0;
  bool fftPass = fftPeak > 0 && fftError < 15.0;

  String status;

  if (!freqPass)
  {
    status = "FAIL";
  }
  else if (freqPass && fftPass)
  {
    status = "PASS";
  }
  else
  {
    status = "WARN";
  }

  // OLED 1 : generation + acquisition
  oled1.clearDisplay();
  oled1.setTextSize(1);
  oled1.setTextColor(SSD1306_WHITE);

  oled1.setCursor(0, 0);
  oled1.println("PWM / ADC");

  oled1.setCursor(0, 20);
  oled1.print("SET:");
  oled1.print(freq);
  oled1.print("Hz");

  oled1.setCursor(0, 31);
  oled1.print("Duty:");
  oled1.print(dutyPercent);
  oled1.print("%");

  oled1.setCursor(0, 42);
  oled1.print("ADC:");
  oled1.print(avgV, 2);
  oled1.print("V");

  oled1.setCursor(0, 53);
  oled1.print("AVG:");
  oled1.print(smoothVoltage, 2);
  oled1.print(" RNG:");
  oled1.print(rangeV, 2);

  oled1.display();

  // OLED 2 : frequence + FFT + diagnostic
  oled2.clearDisplay();
  oled2.setTextSize(1);
  oled2.setTextColor(SSD1306_WHITE);

  oled2.setCursor(0, 0);
  oled2.println("FREQ / FFT");

  oled2.setCursor(0, 20);
  oled2.print("MEAS:");
  oled2.print(measuredFreq, 0);
  oled2.print("Hz");

  oled2.setCursor(0, 31);
  oled2.print("FFT:");
  oled2.print(fftPeak, 0);
  oled2.print("Hz");

  oled2.setCursor(0, 42);
  oled2.print("E1:");
  oled2.print(freqError, 1);
  oled2.print("%");

  oled2.setCursor(62, 42);
  oled2.print("E2:");
  oled2.print(fftError, 1);
  oled2.print("%");

  oled2.setCursor(0, 53);
  oled2.print("Status:");
  oled2.print(status);

  oled2.display();

  Serial.print("SET=");
  Serial.print(freq);
  Serial.print("Hz, Duty=");
  Serial.print(dutyPercent);
  Serial.print("%, ADC=");
  Serial.print(avgV, 3);
  Serial.print("V, AVG=");
  Serial.print(smoothVoltage, 3);
  Serial.print("V, RNG=");
  Serial.print(rangeV, 3);
  Serial.print("V, MEAS=");
  Serial.print(measuredFreq);
  Serial.print("Hz, FFT=");
  Serial.print(fftPeak);
  Serial.print("Hz, E1=");
  Serial.print(freqError);
  Serial.print("%, E2=");
  Serial.print(fftError);
  Serial.print("%, Status=");
  Serial.println(status);

  delay(200);
}
