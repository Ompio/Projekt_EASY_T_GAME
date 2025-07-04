# Turn-Based Tactical Game

## Project Description
This project is a turn-based tactical game with RPG elements, developed in C++ using the SFML library for graphics. The game features a unit management system, movement and combat mechanics, as well as basic artificial intelligence for enemy units. The primary goal was to create an interactive, turn-based gameplay experience on a dynamic board.

## Key Features
* **Turn System:** Manages the order of turns for player and AI units.
* **Unit Movement:** Units can move across the game board based on their speed and movement range.
* **Combat System:** Units can attack enemies within range, distinguishing between melee (`runner`) and ranged (`shooter`) attacks.
* **Artificial Intelligence (AI):** Basic AI implemented for enemy unit movement and attack, focusing on targets with the lowest HP.
* **Graphical Interface:** Utilizes SFML for rendering the board, units, effects, and UI elements (e.g., "wait," "defend" buttons).
* **Game State Management:** Handles win/lose conditions.
* **Texture and Font Handling:** Loading and displaying graphical assets and text.
* **Multithreading:** Employs threads (`std::thread`, `std::binary_semaphore`) for unit loading.

## Technologies Used
* **Programming Language:** C++
* **Graphics Library:** SFML (Simple and Fast Multimedia Library)
* **Standard C++ Libraries:** `<vector>`, `<stack>`, `<tuple>`, `<ranges>`, `<algorithm>`, `<thread>`, `<semaphore>`
* **Data Structures:** `std::vector` (map, entities, targets), `std::stack` (turn queue)

## Project Structure (Selected Files)
* `GraTurowa.cpp`: Contains the main game loop, event handling, rendering, core game logic, and turn management.
* `Ai.h`/`Ai.cpp`: Implements the AI logic for enemy units, including target identification and determining movement/attack actions.
* `unit.h` (assumed, not provided directly, but included in other files): Base class for all in-game units, managing their statistics and common actions.
* `runner.h`/`runner.cpp`: Implements the "runner" unit type (e.g., melee fighter), defining its movement and attack capabilities.
* `shooter.h`/`shooter.cpp`: Implements the "shooter" unit type (e.g., ranged attacker), defining its ranged attack capabilities and specific mechanics.
* `tile_b.h`/`tile_b.cpp`: Class responsible for individual tiles on the game board, their rendering, interactions, and displaying units.
* `functions.h`: Contains definitions for helper structures (e.g., `coords` for coordinates) and global utility functions (e.g., checking sprite hover, finding units on the map).
* `board.h`: (Likely an empty class intended for future board management, based on its current content)

## How to Compile and Run (Example - may require adjustments for your environment)
1.  **Clone the repository:**
2.  **Install SFML:** Ensure you have the SFML library installed on your system. Instructions can be found on the official SFML website (sfml-dev.org).
3.  **Compile the project:** 
* **Using Visual Studio:**
        1.  Open Visual Studio.
        2.  Go to `File` -> `Open` -> `Project/Solution...` and open the `.sln` file if one exists, or create a new project and add the source files.
        3.  Ensure SFML is correctly linked in your project properties (e.g., via Linker -> Input -> Additional Dependencies and VC++ Directories).
        4.  Build the solution (`Build` -> `Build Solution` or F7).
    (If not using CMake, you'll need to manually compile the `*.cpp` files, linking to SFML libraries, e.g., using g++).
4.  **Run the game:**
    ```bash
    ./Projekt_EASY_T_GAME
    ```
    (Or `Debug/Projekt_EASY_T_GAME.exe` for Windows with Visual Studio).

## Project Status
This project was developed as part of a university course assignment and is **no longer under active development**. It showcases the implemented functionalities related to turn-based gameplay, unit movement, combat, and basic AI.
