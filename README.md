
# So_long - 2D Game Project

## Description

*So_long* is a project from 42 school where you are tasked with creating a small 2D video game where a player must collect items, avoid enemies, and reach an exit to win. This project focuses on file manipulation, using graphical libraries, and handling events and game loops. The project uses the *minilibx* library to display graphical elements.

## Project Objectives

- Develop a small interactive 2D game.
- Manipulate files to generate maps (walls, items, enemies, etc.).
- Handle user events (keyboard inputs, window closures).
- Learn to use a simple graphical library.

## Features

The project includes the following features:

### 1. Game Map

- The game is based on a map file of type `.ber`, which represents walls, floors, collectible items, the player's starting position, and the exit.
- The map elements include:
  - `1`: Wall.
  - `0`: Floor.
  - `P`: Player's starting position.
  - `C`: Collectible item.
  - `E`: Exit.
  
### 2. Game Mechanics

- The player can move in four directions (up, down, left, right).
- The goal is to collect all `C` items before being able to access the exit `E`.
- The game ends when the player reaches the exit after collecting all the items.

### 3. Graphics and Events

- Use the *minilibx* library to display the map and player's movements.
- Manage events such as keyboard inputs for movement and window closures.

## Installation

To compile and run the *So_long* project, follow the steps below:

```bash
git clone https://github.com/your-repo/so_long.git
cd so_long
make
```

Then, run the game with a `.ber` map file as an argument:

```bash
./so_long maps/map.ber
```

## Usage

The game is played using the arrow keys to move the character. You must collect all items before reaching the exit. Every movement is counted, and the number of moves is displayed in the terminal.

## Creating Maps

Maps must be in the `.ber` format and follow a rectangular structure, where each element is represented by the aforementioned characters (wall, floor, items, etc.).

Example map:
```
1111111  
100C0E1  
10P0001  
1111111  
```

## Testing

You can test different maps by placing them in the `maps` directory and running the program with these maps as an argument.

```bash
./so_long maps/map2.ber
```

## Author

- **Louis** - 42 Lausanne Student
