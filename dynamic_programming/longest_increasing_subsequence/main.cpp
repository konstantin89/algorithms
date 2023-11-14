#include <iostream>
#include <vector>
#include <algorithm>


// Longest Increasing Subsequence question

// Question: Given an array of integers, find the length of the longest increasing subsequence.
// Solution: Use dynamic programming to keep track of the length of the longest increasing 
//           subsequence ending at each index.

int LongestIncreasingSubsequenceLength(std::vector<int> nums)
{
    std::vector<int> lengths(nums.size(), 0);

    for (int i=1; i<nums.size(); i++)
    {
        if (nums[i] > nums[i-1])
        {
            lengths[i] = lengths[i-1] + 1;
        }
        else
        {
            lengths[i] = 1;
        }
    }

    auto maxElementIter = std::max_element(lengths.begin(), lengths.end());
    return *maxElementIter;
}

int main()
{
    std::vector<int> vec1 = {2,1,2,1,2,3,4,5};

    auto result = LongestIncreasingSubsequenceLength(vec1);
    std::cout << result << std::endl;

    return 0;
}