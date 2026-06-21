Embedded Signal Analyzer & Test Bench
Présentation
Dans le cadre de ma reconversion vers l’électronique, j’ai souhaité développer un projet allant au-delà d’un simple montage Arduino ou d’une démonstration de capteur.
L’objectif de ce projet est de concevoir un mini banc de test électronique basé sur un ESP32 capable de générer, mesurer et analyser des signaux, en reproduisant à petite échelle certaines fonctions utilisées dans les équipements de validation, de diagnostic et de maintenance électronique.
Ce projet combine électronique analogique, électronique numérique, acquisition de données et traitement du signal.


⸻


Fonctionnalités
Génération de signal
Génération PWM
Réglage de la fréquence
Réglage du rapport cyclique (Duty Cycle)
Acquisition analogique
Mesure de tension par ADC
Tension instantanée
Tension lissée
Valeur minimale
Valeur maximale
Calcul du Range (stabilité du signal)
Analyse fréquentielle
Mesure de fréquence
Analyse FFT
Comparaison fréquence générée / fréquence mesurée
Calcul d’erreur
Diagnostic
Validation automatique du signal
États PASS / WARN / FAIL


⸻


Matériel utilisé
ESP32 DevKit
Écran OLED SSD1306
Potentiomètres
Transistor PN2222
LED
Résistances
Condensateurs
Breadboard


⸻


Architecture du système
Génération
Potentiomètre → ESP32 → PWM
Conditionnement du signal
PWM → Filtre RC → Acquisition ADC
Analyse
PWM → Mesure de fréquence
PWM → Analyse FFT
Diagnostic
Mesures → Validation → PASS / WARN / FAIL


⸻


Fonctionnalités développées
Affichage OLED
Génération PWM
Réglage de fréquence
Réglage du Duty Cycle
Filtre RC
Acquisition ADC
Calcul Min / Max / Moyenne
Moyenne glissante
Mesure de fréquence
Analyse FFT
Diagnostic automatique avancé
Double affichage OLED


⸻


Exemple de mesures
Générateur
PWM : 2500 Hz
Duty Cycle : 60 %
Analyse analogique
ADC : 1,98 V
Tension lissée : 1,95 V
Range : 0,03 V
Analyse fréquentielle
Fréquence mesurée : 2498 Hz
Pic FFT : 2501 Hz
Erreur : 0,1 %
Résultat
PASS


⸻


Ce que ce projet m’a permis d’apprendre
Génération PWM
Fonctionnement des filtres RC
Acquisition analogique sur ESP32
Filtrage numérique par moyenne glissante
Mesure de fréquence
Analyse fréquentielle par FFT
Théorème de Nyquist
Traitement du signal
Méthodes de test et de validation électronique
L’objectif n’était pas uniquement d’obtenir un système fonctionnel, mais de comprendre chaque étape du traitement du signal, depuis sa génération jusqu’à son analyse.


⸻


Journal de développement
Le développement du projet est documenté étape par étape :
OLED SSD1306
Génération PWM
Filtre RC
Acquisition ADC
Moyenne glissante
Mesure de fréquence
Analyse FFT
Diagnostic automatique
Double affichage OLED
La documentation détaillée est disponible dans le dossier docs.


⸻


Évolutions prévues
Double affichage OLED
Analyse FFT avancée
Détection automatique de défauts
Journalisation des mesures
Sauvegarde sur carte SD
Interface Web Wi-Fi
Tableau de bord temps réel
Auto-test matériel


⸻


Auteur
Paul Malye
Projet personnel réalisé dans le cadre de ma reconversion vers l’électronique embarquée, les systèmes de test et l’analyse de signaux.
