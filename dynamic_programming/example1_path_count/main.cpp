// Problem:

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    
    std::vector<std::vector<int>> c(m, std::vector<int>(n, 0));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == 0 || j == 0)
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1] +  c[i-1][j];
            }
        }
    }

    return c[m-1][n-1];
}

int main()
{
    auto result = uniquePaths(3,7);
    // correct result is 28

    std::cout << "m=3, n=7, result is " << result << std::endl;

    result = uniquePaths(3,2);
    // correct result is 3

    std::cout << "m=3, n=2, result is " << result << std::endl;

    return 0;
}