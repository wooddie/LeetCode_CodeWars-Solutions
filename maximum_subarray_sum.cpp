#include <iostream>
#include <cassert>
#include <vector>

int maxSequence(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }

    int current_sum = 0;
    int max_sum = 0;

    for (size_t i = 0; i != arr.size(); ++i)
    {
        current_sum = std::max(arr[i], current_sum + arr[i]);
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main()
{
    assert(maxSequence({}) == (0));

    assert(maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == (6));

    return 0;
}