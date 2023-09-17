// Problem Statement: Shortest Path in a Maze

// You are given a 2D grid representing a maze. The maze consists of open cells 
// represented by '0' and walls represented by '1'. You start at the top-left 
// corner of the maze and your goal is to reach the bottom-right corner. 
// You can move in four directions: up, down, left, or right.

// Write a C++ function that takes the maze as input and returns the length 
// of the shortest path from the top-left corner to the bottom-right corner. 
// If there is no path, return -1.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>>& maze) 
{
    int rows = maze.size();
    int cols = maze[0].size();

    // Define possible moves (up, down, left, right)
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;

    // Start from the top-left corner
    q.push({0, 0});
    distance[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // Check all possible moves
        for (int i = 0; i < 4; ++i) {
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];

            // Check if the new position is valid and unvisited
            if ((x >= 0) && (x < rows) && (y >= 0) && (y < cols) && 
                (maze[x][y] == 0) && (distance[x][y] == -1)) 
            {
                // Update the distance and enqueue the new position
                distance[x][y] = distance[curr.first][curr.second] + 1;
                q.push({x, y});
            }
        }
    }

    // Check if the destination is reached
    if (distance[rows - 1][cols - 1] == -1)
        return -1;

    return distance[rows - 1][cols - 1];
}

int main() 
{
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    int result = shortestPath(maze);

    if (result != -1)
        cout << "Shortest Path Length: " << result << endl;
    else
        cout << "No path exists." << endl;

    return 0;
}