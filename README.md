# ProjetData — Moniteur de fréquence cardiaque connecté (ESP32 + PostgreSQL)

Objet connecté qui mesure le **rythme cardiaque** d'une personne et le **niveau de la batterie**, puis enregistre ces mesures dans une base de données **PostgreSQL** via le Wi-Fi.

## Fonctionnement

1. La carte se connecte au réseau Wi-Fi puis à la base de données PostgreSQL (bibliothèque `libpq`).
2. Toutes les 10 secondes :
   - la classe `pulse` lit le capteur cardiaque DFRobot et calcule le rythme (battements par minute) ;
   - la classe `diviseur` lit la tension de la batterie à travers un diviseur de tension (broche `A3`) et calcule un pourcentage ;
   - les valeurs sont insérées dans la table `records` avec le numéro de série de l'appareil.

## Matériel

- Carte ESP32 (framework Arduino)
- Capteur de fréquence cardiaque **DFRobot Heart Rate Sensor**
- Diviseur de tension pour mesurer la batterie
- Un serveur PostgreSQL accessible depuis le réseau

## Structure

```
include/
├── diviseur.h      # Classe de mesure de la tension de la batterie
├── pulse.h         # Classe de lecture du capteur cardiaque
└── libpq-fe.h, postgres*.h, pg_config*.h   # En-têtes PostgreSQL (libpq)
src/
├── main.cpp        # Connexion Wi-Fi/BD et boucle de mesure
├── diviseur.cpp
└── pulse.cpp
```

## Installation

1. Ouvrir le projet avec **PlatformIO** (VS Code).
2. Installer la bibliothèque `DFRobot_Heartrate`.
3. Créer un fichier `include/secret.h` (non publié) contenant le nom du réseau Wi-Fi, son mot de passe, le numéro de série de l'appareil et les informations de connexion à la base de données.
4. Créer la table `records` dans PostgreSQL (numéro de série, rythme cardiaque, pourcentage de batterie).
5. Téléverser le programme et ouvrir le moniteur série à **115200 bauds**.

## Améliorations prévues

- Insérer les vraies valeurs mesurées dans la requête SQL (requête paramétrée avec `PQexecParams`).
- Ne pas fermer la connexion à la base de données après chaque envoi.

## Auteur

**Daniel Nganjip** — projet réalisé en 2023.
