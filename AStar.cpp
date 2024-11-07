#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
const int ROWS = 20;
const int COLS = 20;
const int NODE_SIZE = WIDTH / COLS;

struct Node {
    int x, y;
    bool isWall = false;
    bool visited = false;
    bool isPath = false; // New flag to mark nodes in the final path
    Node* parent = nullptr;
    float g = INFINITY;
    float h = 0.0f;

    float f() const { return g + h; }

    bool operator==(const Node& other) const { return x == other.x && y == other.y; }
};

struct NodeHash {
    size_t operator()(const Node& node) const {
        return hash<int>()(node.x) ^ (hash<int>()(node.y) << 1);
    }
};

// Custom comparator for priority_queue
struct CompareNodes {
    bool operator()(Node* a, Node* b) const {
        return a->f() > b->f();
    }
};

vector<Node*> getNeighbors(Node& node, vector<vector<Node>>& grid) {
    vector<Node*> neighbors;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int nx = node.x + dx[i];
        int ny = node.y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < ROWS && ny < COLS) {
            neighbors.push_back(&grid[nx][ny]);
        }
    }
    return neighbors;
}

float heuristic(const Node& a, const Node& b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan distance
}

void aStar(Node& start, Node& goal, vector<vector<Node>>& grid) {
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;
    start.g = 0;
    start.h = heuristic(start, goal);
    openSet.push(&start);

    unordered_map<Node, bool, NodeHash> openSetMap;
    openSetMap[start] = true;

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();
        openSetMap[*current] = false;

        if (*current == goal) {
            // Trace the final path from goal to start
            while (current) {
                current->isPath = true;
                current = current->parent;
            }
            return;
        }

        current->visited = true;

        for (Node* neighbor : getNeighbors(*current, grid)) {
            if (neighbor->isWall || neighbor->visited) continue;

            float tempG = current->g + 1;
            if (tempG < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tempG;
                neighbor->h = heuristic(*neighbor, goal);

                if (!openSetMap[*neighbor]) {
                    openSet.push(neighbor);
                    openSetMap[*neighbor] = true;
                }
            }
        }
    }
}

void drawGrid(sf::RenderWindow& window, vector<vector<Node>>& grid, Node& start, Node& goal) {
    for (int x = 0; x < ROWS; ++x) {
        for (int y = 0; y < COLS; ++y) {
            sf::RectangleShape rect(sf::Vector2f(NODE_SIZE, NODE_SIZE));
            rect.setPosition(x * NODE_SIZE, y * NODE_SIZE);

            if (&grid[x][y] == &start)
                rect.setFillColor(sf::Color::Green); // Start node
            else if (&grid[x][y] == &goal)
                rect.setFillColor(sf::Color::Red);   // Goal node
            else if (grid[x][y].isPath)
                rect.setFillColor(sf::Color::Yellow); // Final path
            else if (grid[x][y].visited)
                rect.setFillColor(sf::Color(100, 100, 250)); // Visited nodes
            else if (grid[x][y].isWall)
                rect.setFillColor(sf::Color::Black);  // Walls
            else
                rect.setFillColor(sf::Color::White);  // Unvisited nodes

            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1);
            window.draw(rect);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "A* Pathfinding Visualizer");

    // Initialize grid
    vector<vector<Node>> grid(ROWS, vector<Node>(COLS));
    for (int x = 0; x < ROWS; ++x) {
        for (int y = 0; y < COLS; ++y) {
            grid[x][y] = {x, y};
        }
    }

    // Start and Goal
    Node& start = grid[0][0];
    Node& goal = grid[ROWS - 1][COLS - 1];

    // Example wall
    for (int i = 5; i < 15; ++i) {
        grid[10][i].isWall = true;
    }

    // Run A* algorithm
    aStar(start, goal, grid);

    // Main render loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawGrid(window, grid, start, goal);
        window.display();
    }

    return 0;
}
