// Problem Statement: Shortest Path with Weighted Moves in a Maze

// You are given a 2D grid representing a maze. 
// The maze consists of open cells represented by '0' and walls represented by '1'. 
// You start at the top-left corner of the maze and your goal is to reach the bottom-right corner. 
// You can move in four directions: up, down, left, or right. However, each move has a weight associated 
// with it.

// The weights for each move are as follows:

//     Moving up or down has a cost of 'U' (a positive integer).
//     Moving left or right has a cost of 'L' (a positive integer).

// Write a C++ function that takes the maze, the costs 'U' and 'L', as input and returns the minimum 
// cost to reach the bottom-right corner from the top-left corner. If there is no path, return -1.

#include <iostream>
#include <vector>
#include <queue>

using Maze = std::vector<std::vector<int>>;

constexpr int COST_NOT_VISITED = -1;

struct Cell
{
    int x;
    int y;
    int cost;
};

// U - up/down cost
// V - right/left cost
int GetShortestPath(Maze maze, int U, int L)
{
    auto mazeDim = maze[0].size();

    std::vector<std::vector<Cell>> field(mazeDim, std::vector<Cell>(mazeDim));

    for(auto x=0; x<mazeDim; x++)
    {
        for(auto y=0; y<mazeDim; y++)
        {
            field[x][y].x = x;
            field[x][y].y = y;
            field[x][y].cost = COST_NOT_VISITED;
        }
    }

    std::queue<Cell> q;
    field[0][0].cost = 0; // Important! Notice this.
    q.push(field[0][0]);

    const std::vector<int> dx = {1, -1, 0 , 0};
    const std::vector<int> dy = {0, 0, 1 , -1};

    while(!q.empty())
    {
        Cell cell = q.front();
        q.pop();
   
        for (auto i=0; i<dx.size(); i++)
        {
            auto currX = cell.x + dx[i];
            auto currY = cell.y + dy[i];

            if ((currX >= 0) && (currX < mazeDim) &&
                (currY >= 0) && (currY < mazeDim) &&
                (maze[currX][currY] == 0))
            {
                int moveCost = (i<2) ? U : L;
                int newCost = cell.cost + moveCost;

                if ((field[currX][currY].cost == COST_NOT_VISITED) ||
                    (field[currX][currY].cost > newCost))
                {
                    field[currX][currY].cost = newCost;
                    q.push(field[currX][currY]);
                }
            }
        }
    }

    return field[mazeDim-1][mazeDim-1].cost;
}

void RunMaze(Maze maze, int U, int L)
{
    int result = GetShortestPath(maze, U, L);

    if (result != -1)
        std::cout << "Minimum Cost to Reach the Destination: " << result << std::endl;
    else
        std::cout << "No path exists." << std::endl;

}

int main() 
{
    Maze maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    RunMaze(maze, 2, 1);

    RunMaze(maze, 1, 1);

    return 0;
}
