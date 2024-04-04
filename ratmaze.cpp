#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a cell is valid (within bounds, unblocked, and not visited)
bool isSafe(int x, int y, int row, int col, const int maze[][4], vector<vector<bool>>& visited) {
    return (x >= 0 && x < row) && (y >= 0 && y < col) && maze[x][y] == 1 && !visited[x][y];
}

// Recursive function to find all possible paths
void findPaths(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited) {
    // Base case: reached destination (bottom right corner)
    if (srcx == row - 1 && srcy == col - 1) {
        cout << output << endl;
        return;
    }

    // Mark current cell as visited to avoid revisiting
    visited[srcx][srcy] = true;

    // Try all four directions (up, right, down, left) in a specific order
    // (e.g., up, right, down, left) to potentially optimize performance
    // based on the expected maze structure/distribution of blocked cells.
    int newx, newy;

    // Up
    newx = srcx - 1;
    newy = srcy;
    if (isSafe(newx, newy, row, col, maze, visited)) {
        output.push_back('U');
        findPaths(maze, row, col, newx, newy, output, visited);
        output.pop_back(); // Backtrack
    }

    // Right
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(newx, newy, row, col, maze, visited)) {
        output.push_back('R');
        findPaths(maze, row, col, newx, newy, output, visited);
        output.pop_back(); // Backtrack
    }

    // Down
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(newx, newy, row, col, maze, visited)) {
        output.push_back('D');
        findPaths(maze, row, col, newx, newy, output, visited);
        output.pop_back(); // Backtrack
    }

    // Left
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(newx, newy, row, col, maze, visited)) {
        output.push_back('L');
        findPaths(maze, row, col, newx, newy, output, visited);
        output.pop_back(); // Backtrack
    }

    // Unmark current cell (backtracking)
    visited[srcx][srcy] = false;
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 1},
    };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // Check if starting cell is blocked
    if (maze[srcx][srcy] == 0) {
        cout << "No Path Exists" << endl;
    } else {
        visited[srcx][srcy] = true;
        findPaths(maze, row, col, srcx, srcy, output, visited);
    }

    return 0;
}
