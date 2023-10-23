#include <optional>
#include <cstdint>

template <typename ContainerType, typename ValueType>
std::optional<typename ContainerType::size_type> BinarySearch(
    const ContainerType& container, 
    ValueType targetValue)
{
    int64_t beginning = 0;
    int64_t end = container.size() - 1;

    while(beginning <= end)
    {
        int64_t mid = beginning + (end - beginning) / 2;

        if (container.at(mid) == targetValue)
        {
            return mid;
        }

        if (targetValue < container.at(mid))
        {
            end = mid - 1;
        }
        else
        {
            beginning = mid + 1;
        }
    }

    return {};
}