# So_long

## Overview

`So_long` is a custom 2D game developed in the C programming language. This project serves as a simple example of a 2D game, featuring a player character that navigates through a game world filled with obstacles, collectibles, and goals. The game incorporates graphics and input handling, making it an excellent project for learning about game development in C.

This repository contains the source code and assets for the `So_long` game, along with usage instructions and a brief overview of its features.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Prerequisites](#prerequisites)
- [Building and Running So_long](#building-and-running-so_long)
- [Game Controls](#game-controls)
- [Game Assets](#game-assets)
- [License](#license)
- [Acknowledgments](#acknowledgments)
- [Contributions](#contributions)

## Features

- 2D game world with a player character.
- Obstacles, collectibles, and goals to interact with.
- Graphics rendering (using a graphics library like SDL or OpenGL).
- Input handling for player movement and interaction.
- Win/lose conditions and game over state.

## Usage

### Prerequisites

Before running the `So_long` game, you need to have linux and set up for C development. Please refer to the documentation of the specific library you're using for installation instructions.

### Building and Running So_long

1. Clone this repository or download the source code and assets.

3. Use the provided Makefile to build the game. You can choose different compilation options by specifying the target in the Makefile.

    - To build the game with default settings (e.g., using SDL2):

        ```bash
        make
        ```

4. Run the compiled game:

    ```bash
    ./So_long maps/map.ber
    ```

### Game Controls

- Use arrow keys or WASD to move the player character.
- Interact with collectibles and goals by colliding with them.
- Reach the goal to win the game.

## Game Assets

The `assets` directory contains the game's graphics assets, including character sprites, tilesets, and background images. You can customize these assets to create your own game world.

## Acknowledgments

This project was inspired by the need for a simple, educational example of 2D game development in C. It is meant to serve as a starting point for those interested in learning about game development.

## Support 

If you have any questions, encounter issues, or need assistance with the libft project, please feel free to open an issue on GitHub. Im here to help and improve the library together
