#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> res;
    std::unordered_map<int, int> counts;

    for (const auto &num : arr)
    {
        if (counts[num] < n)
        {
            res.push_back(num);
            counts[num]++;
        }
    }

    return res;
}

int main()
{
    assert(deleteNth({20, 37, 20, 21}, 1) == (std::vector<int>({20, 37, 21})));
    assert(deleteNth({1, 1, 3, 3, 7, 2, 2, 2, 2}, 3) == (std::vector<int>({1, 1, 3, 3, 7, 2, 2, 2})));

    return 0;
}