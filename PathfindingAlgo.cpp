#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

const int ROWS = 10;
const int COLS = 10;

class Node {
public:
    int x;
    int y;
    double g_cost;
    double h_cost;
    double f_cost;
    Node* parent;

    Node(int x, int y) : x(x), y(y), g_cost(0), h_cost(0), f_cost(0), parent(nullptr) {}

    bool operator<(const Node& other) const {
        return f_cost > other.f_cost;
    }
};

double heuristic(int x1, int y1, int x2, int y2) {
    // Manhattan distance
    return abs(x1 - x2) + abs(y1 - y2);
}

std::vector<Node*> a_star(int start_x, int start_y, int end_x, int end_y, bool grid[ROWS][COLS]) {
    std::priority_queue<Node> open_list;
    std::unordered_map<int, bool> closed_list;

    Node* start_node = new Node(start_x, start_y);
    Node* end_node = new Node(end_x, end_y);
    start_node->h_cost = heuristic(start_x, start_y, end_x, end_y);
    start_node->f_cost = start_node->g_
