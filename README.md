# Embedded Signal Analyzer & Test Bench

## Présentation

Mini banc de test électronique basé sur ESP32.

Ce projet permet de générer, mesurer et analyser différents signaux électroniques.

Réalisé dans le cadre de ma reconversion vers l'électronique afin de développer des compétences en acquisition de données, traitement du signal et validation électronique.

---

## Objectifs

- Générer un signal PWM réglable
- Mesurer une tension analogique
- Caractériser un signal
- Réaliser une analyse FFT
- Produire un diagnostic automatique

---

## Fonctionnalités

### Génération

- PWM réglable
- Réglage de fréquence
- Réglage du Duty Cycle

### Acquisition

- Filtre RC
- Acquisition ADC
- Moyenne glissante
- Min / Max / Range

### Analyse

- Mesure de fréquence
- FFT
- Validation du signal
- Diagnostic PASS / WARN / FAIL

---

## Architecture du système

### Génération du signal

- Potentiomètre de fréquence
- Potentiomètre de Duty Cycle
- ESP32
- Génération PWM

### Conditionnement analogique

- Sortie PWM
- Filtre RC
- Acquisition ADC
- Calcul de la tension moyenne

### Traitement numérique

- Calcul Min / Max
- Calcul du Range
- Moyenne glissante
- Validation du signal

### Analyse fréquentielle

- Mesure de fréquence
- Analyse FFT
- Comparaison fréquence générée / fréquence mesurée
- Calcul d'erreur

### Interface utilisateur

#### OLED 1 – Génération et acquisition

- Fréquence PWM
- Duty Cycle
- Tension ADC
- Tension lissée
- Range

#### OLED 2 – Analyse et diagnostic

- Fréquence mesurée
- FFT
- Erreur
- Diagnostic PASS / WARN / FAIL


---

## Documentation

La documentation détaillée est disponible dans le dossier `docs`.

### Contenu prévu

- Architecture matérielle
- Journal de développement
- Traitement du signal
- Résultats de tests
- FFT et théorème de Nyquist
- Diagnostic automatique

---

## Évolutions prévues

- Analyse FFT avancée
- Détection automatique de défauts
- Journalisation des mesures
- Sauvegarde sur carte SD
- Interface Web Wi-Fi
- Tableau de bord temps réel
- Auto-test matériel

---

## Auteur

**Paul Malye**

Projet personnel réalisé dans le cadre de ma reconversion vers l'électronique embarquée, les systèmes de test et l'analyse de signaux.
