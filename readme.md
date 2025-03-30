# Dodge 'Em Game

A modern C++ implementation of the classic Atari 2600 game "Dodge 'Em" using SFML graphics library. This game was developed as a semester project for an Object-Oriented Programming course.

![Dodge 'Em Game]

## Description

Dodge 'Em is a driving game based on a single screen of concentric roadways. The player controls a car that moves clockwise, collecting items while avoiding opponent cars that move counter-clockwise. The game features:

- Multiple game levels with increasing difficulty
- Four different types of collectible power-ups
- High score tracking
- Menu system
- Pause functionality

## Gameplay

- **Objective**: Collect all gift boxes in the arena while avoiding enemy cars
- **Controls**: Use W, A, S, D keys to control your car
- **Lives**: Player starts with 3 lives
- **Scoring**: 
  - Red Rectangle: 10 points
  - Green Circle: 20 points + extra life
  - Orange Hexagon: 10 points + speed boost for 10 seconds
  - White Triangle: Makes enemies disappear for 10 seconds

## Game Levels

1. **Level 1**: The opponent car is less active and can't take the top and bottom turns
2. **Level 2**: The opponent car becomes fully active and can take any turn
3. **Level 3**: The opponent car is in active mode with increased speed
4. **Level 4**: Two opponent cars chase the player car in active mode

## Requirements

- C++11 or higher
- SFML 2.5.1 or higher

## Installation

1. Clone the repository:
```
git clone https://github.com/yourusername/dodge-em.git
```

2. Install SFML library:
   - **Windows**: Download from [SFML website](https://www.sfml-dev.org/download.php)
   - **Linux**: `sudo apt-get install libsfml-dev`
   - **macOS**: `brew install sfml`

3. Build the project:
```
cd dodge-em
g++ -c main.cpp
g++ main.o -o dodge-em -lsfml-graphics -lsfml-window -lsfml-system
```

4. Run the game:
```
./dodge-em
```

## Project Structure

- `main.cpp` - Entry point of the game
- `menu.h` - Implements the game menu
- `game.h` - Main game logic
- `player.h` - Player car implementation
- `enemy.h` - Enemy car AI and behavior
- `addons.h` - Collectible items and power-ups
- `img/` - Directory containing game assets

## Contributing

This project was developed as an academic exercise. However, feel free to fork the repository and make your own improvements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Original Dodge 'Em game by Atari
- SFML development team
- Course instructors for the project guidelines