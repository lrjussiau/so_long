
# So_long - 2D Game Project

## Description

*So_long* est un projet de l'école 42 qui consiste à créer un petit jeu vidéo en 2D où un joueur doit collecter des objets, éviter des ennemis et atteindre une sortie pour gagner. Ce projet met l'accent sur la manipulation de fichiers, l'utilisation de bibliothèques graphiques, ainsi que sur la gestion d'événements et de boucles de jeu. Le projet utilise la bibliothèque *minilibx* pour afficher les éléments graphiques.

## Objectifs du projet

- Développer un petit jeu en 2D avec des éléments interactifs.
- Manipuler des fichiers pour générer des cartes (murs, objets, ennemis, etc.).
- Gérer les événements utilisateur (clavier, fermetures de fenêtre).
- Apprendre à utiliser une bibliothèque graphique simple.

## Fonctionnalités

Le projet inclut les fonctionnalités suivantes :

### 1. Carte du jeu

- Le jeu repose sur une carte de type *fichier `.ber`*, qui représente les murs, le sol, les objets à collecter, la position du joueur et la sortie.
- Les éléments de la carte incluent :
  - `1`: Mur.
  - `0`: Sol.
  - `P`: Position de départ du joueur.
  - `C`: Objet à collecter.
  - `E`: Sortie.
  
### 2. Mécanique de jeu

- Le joueur peut se déplacer dans quatre directions (haut, bas, gauche, droite).
- Le but est de collecter tous les objets `C` avant de pouvoir accéder à la sortie `E`.
- Le jeu se termine lorsque le joueur atteint la sortie après avoir ramassé tous les objets.

### 3. Graphismes et événements

- Utilisation de la bibliothèque *minilibx* pour afficher la carte et les mouvements du joueur.
- Gestion des événements comme les touches du clavier pour le déplacement, et la fermeture de la fenêtre.

## Installation

Pour compiler et exécuter le projet *So_long*, suivez les étapes ci-dessous :

\`\`\`bash
git clone https://github.com/votre-repo/so_long.git
cd so_long
make
\`\`\`

Ensuite, lancez le jeu avec une carte `.ber` en argument :

\`\`\`bash
./so_long maps/map.ber
\`\`\`

## Usage

Le jeu se joue avec les touches fléchées pour déplacer le personnage. Vous devez ramasser tous les objets avant de pouvoir atteindre la sortie. Chaque mouvement est comptabilisé, et le nombre de déplacements s'affiche dans le terminal.

## Création de Cartes

Les cartes doivent être au format `.ber` et suivre une structure rectangulaire, où chaque élément est représenté par les caractères mentionnés ci-dessus (mur, sol, objets, etc.).

Exemple de carte :

\`\`\`
1111111

100C0E1

10P0001

1111111
\`\`\`

## Tests

Vous pouvez tester différentes cartes en les plaçant dans le répertoire `maps` et en exécutant le programme avec ces cartes comme argument.

\`\`\`bash
./so_long maps/map2.ber
\`\`\`

## Auteur

- **Louis** - Étudiant à 42 Lausanne
