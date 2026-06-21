Embedded Signal Analyzer & Test Bench
Pourquoi ce projet ?
Dans le cadre de ma reconversion vers l’électronique, je souhaitais développer un projet allant au-delà d’un simple montage Arduino ou d’un capteur connecté.
L’objectif était de concevoir un véritable mini banc de test électronique capable de générer, mesurer et analyser des signaux, en reproduisant à petite échelle certaines fonctions que l’on retrouve dans les équipements de validation, de diagnostic et de maintenance électronique.
Ce projet est construit autour d’un ESP32 et combine électronique analogique, électronique numérique, acquisition de données et traitement du signal.


⸻


Démonstration
Le système permet de :
Générer un signal PWM réglable en fréquence et en rapport cyclique.
Convertir ce signal en tension analogique grâce à un filtre RC.
Mesurer et caractériser cette tension.
Calculer les valeurs minimales, maximales et moyennes.
Appliquer un filtrage numérique par moyenne glissante.
Mesurer la fréquence réelle du signal généré.
Réaliser une analyse fréquentielle par FFT.
Produire un diagnostic automatique PASS / WARN / FAIL.


⸻


Architecture générale
Potentiomètres
       │
       ▼
ESP32
├── Générateur PWM
├── Filtre RC
├── Acquisition ADC
├── Moyenne glissante
├── Fréquencemètre
├── Analyse FFT
└── Diagnostic automatique
       │
       ▼
OLED


⸻


Fonctionnalités
Génération PWM
Réglage en temps réel :
Fréquence du signal
Rapport cyclique (Duty Cycle)
Acquisition analogique
Mesures disponibles :
Tension instantanée
Tension lissée
Valeur minimale
Valeur maximale
Range (stabilité du signal)
Mesure de fréquence
Comparaison entre :
Fréquence demandée
Fréquence réellement mesurée
Analyse FFT
Détection de la fréquence dominante du signal et validation de sa cohérence avec la fréquence générée.
Diagnostic automatique
Le système compare les différentes mesures et affiche :
PASS
WARN
FAIL


⸻


Double affichage OLED (version finale)
OLED 1 — Génération et acquisition
PWM : 2500 Hz
Duty : 60 %

ADC : 1.98 V
Smooth : 1.95 V
Range : 0.03 V
OLED 2 — Analyse fréquentielle
MEAS : 2498 Hz
FFT  : 2501 Hz

Err : 0.1 %
PASS


⸻


Matériel utilisé
ESP32 DevKit
OLED SSD1306
Potentiomètres
Transistor PN2222
LED
Résistances
Condensateurs
Breadboard


⸻


Ce que j’ai appris
Au-delà du montage lui-même, ce projet m’a permis de comprendre concrètement :
Le fonctionnement d’un filtre RC.
La relation entre fréquence, période et rapport cyclique.
L’acquisition analogique sur ESP32.
Le filtrage numérique par moyenne glissante.
La mesure de fréquence.
Les bases de l’analyse fréquentielle par FFT.
La construction d’une chaîne complète de mesure et de diagnostic.
L’objectif n’était pas uniquement d’obtenir un système fonctionnel, mais de comprendre chaque étape du traitement du signal, depuis sa génération jusqu’à son analyse.


⸻


Journal de développement
Le développement du projet est documenté étape par étape :
OLED SSD1306
Génération PWM
Filtre RC
Acquisition ADC
Min / Max / Moyenne / Range
Moyenne glissante
Mesure de fréquence
Analyse FFT
Diagnostic automatique
Double affichage OLED
👉 Voir le journal complet dans le dossier docs/.


⸻


Perspectives d’évolution
Analyse FFT avancée
Détection automatique de défauts
Journalisation des mesures
Carte SD
Interface Web Wi-Fi
Dashboard temps réel
Générateur multi-signaux
Auto-test matériel


⸻


Auteur
Paul Malye
Projet personnel réalisé dans le cadre de ma reconversion vers l’électronique embarquée, les systèmes de test et la validation électronique.
