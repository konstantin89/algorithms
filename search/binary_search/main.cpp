#include <iostream>
#include <vector>
#include <algorithm>

#include "BinarySearch.h"

template <typename Container, typename DataType>
bool TestCase(const Container &container, DataType data)
{
    auto referenceResult = std::binary_search(container.begin(), container.end(), data);
    auto searchResult = BinarySearch(container, data);

    if (referenceResult == searchResult.has_value())
    {
        std::cout << "[V] Test passed" << std::endl;
        return true;
    }
    else
    {
        std::cout << "[X] Test failed" << std::endl;
        return false;
    }
}

int main()
{
    std::vector<int> vec1 = {1,3,5,7,8,12,13,26,45,67,134,156,567};

    for (auto value : vec1)
    {
        TestCase(vec1, value);
    }

    TestCase(vec1, 2);
    TestCase(vec1, 15);
    TestCase(vec1, 789);
    TestCase(vec1, 0);
    TestCase(vec1, 155);

    return 0;
}