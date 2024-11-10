# VerticalVictory - A Connect 4 Game 🧩

![C++](https://img.shields.io/badge/Languages%20&%20Frameworks-C%2B%2B-blue) ![SFML](https://img.shields.io/badge/Languages%20&%20Frameworks-SFML-lightblue)

## Overview
VerticalVictory is a fun and interactive implementation of the classic **Connect 4** game. Players take turns dropping their discs into a grid with the objective of connecting four of their discs in a row—horizontally, vertically, or diagonally. The game is won when a player achieves this connection, or when the grid is full without a winner (a draw).

This project was built using **C++** and **SFML** for graphical user interface (GUI) rendering. The game provides a visually appealing experience with real-time interaction.

<img width="696" alt="Screenshot 2024-11-10 at 4 14 54 PM" src="https://github.com/user-attachments/assets/ba20164f-b3bb-4889-8e68-4027c83500d1">


## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Installing SFML on macOS](#installing-sfml-on-macos)
- [Usage](#usage)
- [Contributing](#contributing)
- [Contact](#contact-)

## Features
- **Two-player gameplay**: Players take turns in a competitive match.
- **Graphical Interface**: A simple and clear display of the Connect 4 grid.
- **Winning and Draw Detection**: Automatic detection of win conditions and draws.
- **Reset Option**: After a match, players can reset the game board and start again.

## Technologies Used
- **C++**: Programming language used to build the core game logic.
- **SFML**: Simple and Fast Multimedia Library for graphical rendering, window management, and event handling.
- **Git/GitHub**: Version control and hosting of the project repository.

## Installation

### Prerequisites
- **C++ compiler** (e.g., g++, clang++)
- **SFML** library installed (For installation details, see below)

### Installing SFML on macOS
1. Install SFML using Homebrew:
   ```bash
   brew install sfml
2. Clone this repository:
   ```bash
   git clone https://github.com/mariarodr1136/VerticalVictory.git
3. Navigate into the project directory:
   ```bash
   cd VerticalVictory
4. Compile the code:
   ```bash
   g++ connect4.cpp -o connect4 -std=c++11 -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
5. Run the game:
   ```bash
   ./connect4

## Usage

- Launch the game by running the compiled executable.
- Players will take turns clicking to drop discs into the grid.
- The game automatically detects if a player has won or if the game is a draw.
- After a game ends, click to reset and start a new match.

## Contributing
Feel free to submit issues or pull requests for improvements or bug fixes. You can also open issues to discuss potential changes or enhancements. All contributions are welcome to enhance the app’s features or functionality!

To contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feat/your-feature-name
- Alternatively, for bug fixes:
   ```bash
   git checkout -b fix/your-bug-fix-name
3. Make your changes and run all tests before committing the changes and make sure all tests are passed.
4. After all tests are passed, commit your changes with descriptive messages:
   ```bash
   git commit -m 'add your commit message'
5. Push your changes to your forked repository:
   ```bash
   git push origin feat/your-feature-name.
6. Submit a pull request to the main repository, explaining your changes and providing any necessary details.

## Contact 🌐
If you have any questions or feedback, feel free to reach out at [mrodr.contact@gmail.com](mailto:mrodr.contact@gmail.com).
