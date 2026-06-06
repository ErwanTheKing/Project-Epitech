# My Hunter 🎯

Un jeu de tir avec caméra fixe développé en C avec la bibliothèque CSFML (Simple and Fast Multimedia Library).

## 📋 Description

**My Hunter** est un jeu de type "Duck Hunt" où le joueur doit tirer sur des oiseaux en mouvement. Le jeu propose différents modes de difficulté et un système de score avec sauvegarde du meilleur score.

### Caractéristiques principales :
- 🎮 Caméra fixée avec des éléments en mouvement
- 🎯 Système de visée et de tir au clic souris
- 🐦 Apparition d'un oiseau toutes les 5 secondes
- ⚡ Augmentation de vitesse toutes les 10 secondes
- 💙 Système de vies
- 🔫 Système de munitions
- 📊 Sauvegarde du meilleur score
- ⏸️ Menu pause (touche Échap)
- ⚙️ Menu paramètres personnalisables

## 🎮 Modes de jeu

Le jeu propose deux modes distincts :

- **Mode Renaud** : Mode normal avec difficulté standard
- **Mode Eric** : Mode God (invincibilité activée)

## 🛠️ Compilation

### Prérequis

- GCC ou tout autre compilateur C
- CSFML (Graphics, Window, System, Audio)
- Make

### Installation des dépendances (Ubuntu/Debian)

```bash
sudo apt-get update
sudo apt-get install libcsfml-dev
```

### Compilation du projet

```bash
make
```

Cela générera l'exécutable `my_hunter`.

### Nettoyage

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime les fichiers objets et l'exécutable
make re         # Recompile entièrement le projet
```

## 🚀 Utilisation

### Lancer le jeu

```bash
./my_hunter
```

### Afficher l'aide

```bash
./my_hunter -h
```

## 🎮 Contrôles

- **Souris** : Visée
- **Clic gauche** : Tir (cooldown de 0.25s entre chaque tir)
- **Échap** : Pause

## ⚙️ Paramètres

Le jeu dispose d'un menu paramètres permettant de configurer :

- **Résolution** : 800x600 ou 1920x1080
- **VSync** : Activation/Désactivation
- **FPS** : 30, 60, 120 ou illimité

## 📁 Structure du projet

```
my_hunter/
├── main.c                      # Point d'entrée du programme
├── Makefile                    # Fichier de compilation
├── help.txt                    # Texte d'aide
├── include/                    # Fichiers d'en-tête
│   ├── functions.h
│   ├── includes.h
│   ├── macro.h
│   └── struct_csfml.h
├── main/                       # Menu principal
│   ├── main_menu.c
│   ├── button_main.c
│   ├── execute_main.c
│   └── text_main.c
├── game/                       # Logique du jeu
│   ├── my_hunter.c
│   ├── execute_hunter.c
│   ├── manage_sprite.c
│   ├── sprite_hunter.c
│   ├── draw_sprite.c
│   ├── destroy_sprite.c
│   ├── ammo_sprite.c
│   ├── text_game.c
│   └── highscore.txt
├── chose_mode/                 # Sélection du mode
│   ├── chose_mode.c
│   └── sprite_chose_mode.c
├── pause/                      # Menu pause
│   ├── pause_menu.c
│   ├── button_pause.c
│   └── execute_pause.c
├── settings/                   # Menu paramètres
│   ├── settings_menu.c
│   ├── button_settings.c
│   ├── button_settings2.c
│   ├── text_settings.c
│   ├── execute_settings.c
│   └── execute_settings2.c
├── loose/                      # Menu défaite
│   ├── loose_menu.c
│   └── sprite_loose.c
└── asset/                      # Ressources
    ├── bg/                     # Arrière-plans
    ├── button/                 # Boutons et UI
    ├── font/                   # Police
    ├── obj/                    # Objets du jeu (oiseaux, munitions, cœurs)
    └── sound/                  # Sons et musiques
```

## 🎨 Assets

Le jeu utilise plusieurs types de ressources :

- **Arrière-plans** : 4 backgrounds de jeu + menus (principal, pause, paramètres, défaite)
- **Sprites** : Oiseaux animés (3 frames), munitions, cœurs de vie, viseur
- **Interface** : Boutons pour tous les menus
- **Audio** : Musique de fond et effets sonores (son de tir)
- **Police** : Police personnalisée pour les textes

## 🎯 Mécaniques de jeu

### Système de difficulté progressive

- Un nouvel oiseau apparaît toutes les 5 secondes
- La vitesse augmente toutes les 10 secondes
- Les oiseaux se déplacent de gauche à droite

### Système de points

- Score basé sur le nombre d'oiseaux touchés
- Sauvegarde automatique du meilleur score dans `game/highscore.txt`
- Affichage du score actuel et du record

### Système de vie et munitions

- Vies limitées (sauf en mode Eric)
- Munitions à gérer
- Affichage graphique des vies et munitions restantes

## 👨‍💻 Auteur

**Erwan Lo Presti**

## 📚 Projet EPITECH

Ce projet a été réalisé dans le cadre de la formation EPITECH en 2025.

## 📄 Licence

Projet EPITECH - Tous droits réservés

---

**Note** : Ce jeu est un projet pédagogique réalisé avec CSFML. Il s'inspire du célèbre jeu "Duck Hunt".

