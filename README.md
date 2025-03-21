# 🏹 Jeu RPG – Aventure et Combat ⚔️  

## 📖 Description  
Ce projet est un jeu de rôle en C++ où le joueur incarne un personnage pouvant affronter des ennemis, rencontrer des alliés et récupérer des objets pour améliorer ses capacités.  

## 🎮 Fonctionnalités  
### 🔥 Combat  
- Système de combat au tour par tour.  
- Attaques basées sur une détermination aléatoire.  
- Possibilité d'utiliser automatiquement une potion si les PV tombent à 0.  

### 🛡️ Équipement  
- Le joueur peut équiper **une seule arme** et **une seule armure**.  
- Les armes augmentent l'attaque, les armures augmentent la défense.  
- Déséquiper un objet réduit la statistique associée.  

### 🎒 Gestion de l'inventaire  
- Ajout et suppression d'objets dans l’inventaire.  
- Affichage détaillé du contenu de l’inventaire.  

### 🤝 Alliés  
- Les alliés sont rencontrés par le joueur et peuvent lui offrir un objet selon son choix. 

### 💾 Sauvegarde et Chargement  
- Sauvegarde de la progression dans un fichier `.txt`.  
- Chargement d’une partie sauvegardée pour reprendre l’aventure.  

## 🏗️ Structure des fichiers  
- `main.cpp` : Point d'entrée du jeu.  
- `jeu.cpp / jeu.hpp` : Gestion du déroulement du jeu.  
- `joueur.cpp / joueur.hpp` : Implémentation du personnage joueur.  
- `ennemi.cpp / ennemi.hpp` : Gestion des ennemis.
- `allie.cpp / allie.hpp` : Gestion des alliés.
- `personnage.cpp / personnage.hpp` : Classe de base pour tous les personnages.  
- `objet.cpp / objet.hpp` : Gestion des objets et équipements.
- `potion.hpp` : Classe de l'objet potion.
- `arme.hpp` : Classe de l'objet arme.
- `armure.hpp` : Classe de l'objet armure.
- `Makefile` : Compilation et nettoyage du projet.  

## 🔧 Compilation et Exécution  
### Avec Makefile  
```bash
make          # Compilation du jeu
./monjeu      # Lancer le jeu
make clean    # Nettoyer les fichiers objets
make clean_txt # Nettoyer les fichiers txt