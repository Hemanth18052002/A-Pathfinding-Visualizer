# A* Pathfinding Visualizer

A C++ project using SFML to visualize the A* pathfinding algorithm on a 2D grid.

## Features
- Interactive grid-based visualization of A* algorithm
- Adjustable start and goal points
- Obstacles and walls for testing pathfinding
- Visualization of visited nodes and the shortest path

## Demo
![A* Visualizer Demo](assets/demo.gif)

## Installation
[Youtube Video](https://youtu.be/rZE700aaT5I?si=u1IdfY_vDQfHFcPy)
1. **Install SFML** by following [this guide](https://www.sfml-dev.org/tutorials/).
2. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/astar-visualizer.git
    cd astar-visualizer
    ```
3. **Build**:
    ```bash
    g++ -std=c++20 -I path_to_sfml_include -L path_to_sfml_lib main.cpp -o astar -lsfml-graphics -lsfml-window -lsfml-system
    ```

## Usage
- Run the program and view the A* algorithm in action.
- Add walls by clicking on cells, set a start and goal, and visualize the shortest path.

## Acknowledgments
This project was inspired by the need to visualize A* pathfinding and uses the SFML library.
