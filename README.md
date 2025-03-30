# Dodge 'Em - Project Description

## Overview
This is a modern C++ implementation of the classic Atari 2600 game "Dodge 'Em" released in 1980. The game was originally programmed by Carla Meninsky and released by Sears for the "Sears Video Arcade" under the name "Dodger Cars". Our implementation uses the SFML (Simple and Fast Multimedia Library) for graphics rendering.

## Game Concept
Dodge 'Em is a driving game based on a single screen of concentric roadways. The player navigates a car through these roadways, collecting items while avoiding opponent cars controlled by the computer.

## Gameplay Mechanics

### Player vs. Opponent
- The player drives a brown colored car to collect rewards while avoiding collisions with blue opponent cars
- The player car moves clockwise while opponent cars move counter-clockwise
- Each player starts with three lives
- Players earn 10 points when collecting rectangular-shaped gift boxes placed in the arena
- When the player car collides with an opponent car, one life is lost and the arena is refilled with gift boxes
- Score and remaining lives are displayed at the top of the screen

### Driving Rules
- Each roadway has four turns, one after each quarter of the roadway
- The player car starts from the middle of the topmost roadway
- Opponent cars start randomly at any turn, at least one turn away from the player car on the same roadway
- The player controls their car using the W, A, S, D keys
- Opponent cars decide whether to take turns based on the distance from the player car, taking turns if it brings them closer to the roadway where the player car is moving

### Game Levels
1. **Level 1**: The opponent car is less active and cannot take top or bottom turns on any roadway, while the player can take any of the four turns to avoid collisions
2. **Level 2**: The opponent car becomes fully active and can take any turn just like the player car
3. **Level 3**: The opponent car is in active mode with increased speed
4. **Level 4**: Two opponent cars chase the player car in active mode as in level 2, but starting from different locations. Upon completing level 4, the game ends with a "You won!" message

### Types of Food/Powerups
The game features four types of collectible items:
1. **Red Rectangle**: Awards 10 points
2. **Green Circle**: Gives an extra life and 20 points
3. **Orange Hexagon**: Increases player speed by 1.5x for 10 seconds and gives 10 points
4. **White Triangle**: Makes enemy cars disappear for 10 seconds

### High Scores
- When the game starts, high scores are read from a file (highscores.txt)
- Scores are stored in an array of size 5
- If the current game score makes it to the high score list, the lowest score is removed and the updated list is saved back to the file

### Menu System
The game includes a menu-driven interface with the following options:
1. Start a new game
2. See high scores
3. Help (displays game rules and controls)
4. Exit

During gameplay, pressing the 'P' key pauses the game and displays a similar menu with an additional "Continue" option.

## Technical Implementation
- Written in C++ using object-oriented programming principles
- Graphics rendering using SFML library
- Class hierarchy with inheritance for various game elements
- Collision detection between cars and collectibles
- File I/O for saving/loading high scores
- Game state management for different levels and menus

## Controls
- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **P**: Pause game
- **ESC**: Exit current screen/Return to menu

## Project Status
This game was developed as an academic project for an Object-Oriented Programming course.
