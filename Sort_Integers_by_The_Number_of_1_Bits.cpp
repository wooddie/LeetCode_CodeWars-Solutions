#include <iostream>
#include <vector>
#include <bit>

class Solution
{
public:
    std::vector<int> sortByBits(std::vector<int> &arr)
    {
        std::vector<std::pair<int, int>> helper;
        helper.reserve(arr.size());

        for (const auto &n : arr)
        {
            helper.push_back({__builtin_popcount(n), n});
        }

        std::sort(helper.begin(), helper.end());

        for (int i = 0; i < arr.size(); ++i)
        {
            arr[i] = helper[i].second;
        }

        return arr;
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (const auto &n : s1.sortByBits(vec))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    vec = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    for (const auto &n : s1.sortByBits(vec))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}