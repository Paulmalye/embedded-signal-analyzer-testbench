Embedded Signal Analyzer & Test Bench

Présentation

L’objectif de ce projet est de concevoir un mini banc de test électronique embarqué basé sur un ESP32 capable de générer, mesurer et analyser différents signaux.

Ce système reproduit plusieurs fonctions couramment rencontrées dans les équipements de test et de validation électroniques industriels :

Génération de signaux PWM
Filtrage analogique RC
Acquisition ADC
Mesure de fréquence
Analyse fréquentielle par FFT
Diagnostic automatique PASS / WARN / FAIL
Affichage temps réel sur OLED

Ce projet est réalisé dans le cadre de ma reconversion vers l’électronique et de ma préparation au BTS CIEL (Cybersécurité, Informatique et Réseaux, Électronique).

⸻

Objectifs pédagogiques

Ce projet m’a permis de mettre en pratique :

Les microcontrôleurs ESP32
Les interfaces I2C
Les convertisseurs analogique-numérique (ADC)
La génération PWM
Les filtres RC
Le traitement du signal
Les mesures électroniques
L’analyse fréquentielle (FFT)
Les méthodes de test et de validation

⸻

Architecture du système

ESP32

Générateur PWM
Contrôle fréquence et rapport cyclique
Acquisition ADC
Mesure de fréquence
Analyse FFT
Diagnostic automatique

Périphériques :

OLED SSD1306
Potentiomètres de réglage
Filtre RC
Transistor PN2222
LED de visualisation

⸻

Fonctionnalités

Générateur PWM

Réglage en temps réel :

Fréquence
Rapport cyclique (Duty Cycle)

Analyse analogique

Mesures disponibles :

Tension instantanée
Tension lissée
Valeur minimale
Valeur maximale
Amplitude (Range)

Mesure de fréquence

Comparaison entre :

Fréquence demandée
Fréquence réellement mesurée

Analyse FFT

Détermination de la fréquence dominante du signal.

Diagnostic automatique

Évaluation automatique :

PASS
WARN
FAIL

⸻

Écrans OLED

OLED 1 : Génération et acquisition

PWM
Duty Cycle
Tension ADC
Moyenne glissante
Range

OLED 2 : Analyse et diagnostic

Fréquence mesurée
FFT
Erreur
Diagnostic

⸻

Matériel utilisé

ESP32 DevKit
OLED SSD1306
Potentiomètres 10 kΩ
PN2222
LED
Résistances
Condensateurs
Breadboard

⸻

Compétences démontrées

Électronique analogique
Électronique numérique
Systèmes embarqués
Traitement du signal
Acquisition de données
Instrumentation
Validation et diagnostic

⸻

Développement

Étape 1

OLED SSD1306

Étape 2

Génération PWM

Étape 3

Filtre RC et mesures ADC

Étape 4

Min / Max / Moyenne / Range

Étape 5

Mesure de fréquence

Étape 6

Analyse FFT

Étape 7

Diagnostic automatique

Étape 8

Double affichage OLED

⸻

Auteur

Paul Malye

Projet personnel de reconversion vers l’électronique embarquée et les systèmes de test.
