#include <iostream>
#include <vector>

// The problem:
// An array weights representing the weights of the items.
// An array values representing the values of the items.
// An integer W representing the weight limit.
// The function should return the maximum value that can be obtained.
int maxKnapsackValue(const std::vector<int>& weights, const std::vector<int>& values, int W) 
{
    // values.size() is same as weights.size().
    int numberOfItems = values.size();

    // Initialize a 2D vector to store the maximum values for subproblems
    std::vector<std::vector<int>> maxValues(numberOfItems + 1, std::vector<int>(W + 1, 0));

    // Build the table of maximum values using dynamic programming
    for (int i = 1; i <= numberOfItems; ++i) 
    {
        for (int w = 1; w <= W; ++w) 
        {
            // Check if including the current item would exceed the weight limit
            if (weights[i - 1] <= w) 
            {
                // Decide whether to include the current item or not

                // values[i - 1] - current item
                maxValues[i][w] = 
                std::max(
                    // If we include the item in the sack
                    values[i - 1] + maxValues[i - 1][w - weights[i - 1]],
                    // If we don't include it
                    maxValues[i - 1][w]);
            } 
            else 
            {
                // If including the current item exceeds the weight limit, exclude it
                maxValues[i][w] = maxValues[i - 1][w];
            }
        }
    }

    // The result is stored in the bottom-right cell of the table
    return maxValues[numberOfItems][W];
}

int main()
{
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 6};
    int weightLimit = 5;

    int result = maxKnapsackValue(weights, values, weightLimit);
    // Expected Output: 7
    // Explanation: Select items with weights 2 and 3 to maximize the total value (3 + 4).

    std::cout << result << std::endl;

    return 0;
}