# A* Pathfinding Visualizer

A C++ project using SFML to visualize the A* pathfinding algorithm on a 2D grid.

# Concept
The A* (A-star) algorithm is a popular and efficient pathfinding algorithm widely used in games, robotics, and artificial intelligence to find the shortest path from a start point to an endpoint on a grid or map. The A* algorithm combines the principles of Dijkstra’s algorithm and Greedy Best-First Search, utilizing both path cost and heuristic (estimated cost to reach the goal) to make informed decisions while traversing a grid.

## Core Concepts of A* Algorithm
### Grid Representation:

The 2D grid is divided into cells or nodes, where each cell has coordinates (x, y). These cells represent possible positions or locations in the search space.<br />
Certain cells can be marked as obstacles, making them non-traversable. <br />
### Cost Functions:

A* relies on three key cost functions:<br />
g(n): The exact cost to reach a node n from the start node.<br />
h(n): The heuristic estimated cost to get from node n to the goal node. Common heuristic functions include:<br />
Manhattan Distance (|x1 - x2| + |y1 - y2|): Suitable for grids where movement is restricted to four directions (up, down, left, right).<br />
Euclidean Distance (√((x1 - x2)^2 + (y1 - y2)^2)): Useful when diagonal movement is allowed.<br />
Diagonal Distance: Suitable when diagonal moves have the same cost as horizontal and vertical moves.<br />
f(n): The total cost function, calculated as:<br />
f(n)=g(n)+h(n)<br />
This is the score that determines the "priority" of each node in A*, combining the known path cost and the heuristic estimate.<br />
### Open and Closed Lists:

Open List: A priority queue of nodes that need to be evaluated. Nodes are sorted by their f(n) values, with the lowest value (most promising path) at the front.<br />
Closed List: A set of nodes that have already been evaluated to prevent reprocessing and looping.<br />
### Heuristics and Admissibility:

A*’s heuristic function h(n) is said to be admissible if it never overestimates the cost to reach the goal, ensuring that A* finds an optimal path if it exists.<br />
An admissible heuristic guarantees that A*’s solution is optimal, while an inconsistent heuristic (one that sometimes overestimates) might still provide quick, although not necessarily optimal, paths.<br />



## Features
- Interactive grid-based visualization of A* algorithm
- Adjustable start and goal points
- Obstacles and walls for testing pathfinding
- Visualization of visited nodes and the shortest path

## Demo
<img width="401" alt="{78DE140F-C22F-416A-95B1-605BA378F7FF}" src="https://github.com/user-attachments/assets/b208dd0e-19b4-456d-8a5e-3d9c94a64cfd">


## Installation
[Youtube Video](https://youtu.be/rZE700aaT5I?si=u1IdfY_vDQfHFcPy)
1. **Install SFML** by following [this guide](https://www.sfml-dev.org/tutorials/).
2. **Clone the Repository**:
    ```bash
    git clone [https://github.com/yourusername/astar-visualizer.git](https://github.com/Hemanth18052002/A-Pathfinding-Visualizer.git)
    cd A-Pathfinding-Visualizer
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
