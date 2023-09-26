#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

namespace merge_sort
{

template <typename DataType, typename Compare>
void _internal_merge(std::vector<DataType>& vec, Compare comp, size_t begin, size_t end, size_t mid)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    
    // Create temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = vec[begin + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    size_t i = begin;

    while ((!L.empty()) && (!R.empty()))
    {
        if (comp(R.front(), L.front()))
        {
            vec[i] = R.front();
            R.erase(R.begin());
        }
        else
        {
            vec[i] = L.front();
            L.erase(L.begin());        
        }

        i++;
    }

    while (!L.empty())
    {
        vec[i] = L.front();
        L.erase(L.begin());
        i++; 
    }

    while (!R.empty())
    {
        vec[i] = R.front();
        R.erase(R.begin()); 
        i++; 
    }
}

template <typename DataType, typename Compare>
void _internal_sort(std::vector<DataType>& vec, Compare comp, size_t begin, size_t end)
{
    if (begin >= end)
    {
        return;
    }

    size_t mid = (begin+end)/2;
    _internal_sort(vec, comp, begin, mid);
    _internal_sort(vec, comp, mid+1, end);
    _internal_merge(vec, comp, begin, end, mid);
}

template <typename DataType, typename Compare>
void sort(std::vector<DataType>& vec, Compare comp)
{
    size_t begin = 0;
    size_t end = vec.size() - 1;
    _internal_sort(vec, comp, begin, end);
}

}// namespace merge_sort


int main()
{
    auto print = [](const int& n) { std::cout << n << ' '; };

    std::vector<int> vec1 = {2,6,1,-2,0,1,5,7,9,3,-5,21,0};

    std::for_each(vec1.begin(), vec1.end(), print);
    std::cout << std::endl;

    merge_sort::sort<int, std::greater<int>>(vec1, std::greater<int>());

    std::for_each(vec1.begin(), vec1.end(), print);
    std::cout << std::endl;

    merge_sort::sort<int, std::less<int>>(vec1, std::less<int>());

    std::for_each(vec1.begin(), vec1.end(), print);
    std::cout << std::endl;

    return 0;
}