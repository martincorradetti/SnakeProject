# **SnakeProject**

A simple Snake game using custom-designed data structures and ncurses for terminal graphics.

## **About**
SnakeProject is a terminal-based game built with a focus on modularity, custom data structures, and reusable components.

## **Features**
- Modular **ncurses-based API** for rendering and input.
- Custom data structures:
  - **Doubly linked list** for managing levels.
  - **Array** for managing the snake.
  - **2D arrays** for levels (using flat arrays for efficiency).
  - **Custom hashMap** for the game database.
- Highly customizable and extendable architecture.

## **How to Build**
1. Clone the repository:
   ```bash
   git clone https://github.com/martincorradetti/SnakeProject.git
   cd SnakeProject
2. Compile
    ```bash
    mkdir build
    cd build
    cmake ..
    make
3. Run
    ```bash
    ./snake

## **License**
[![GPLv3 License](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

