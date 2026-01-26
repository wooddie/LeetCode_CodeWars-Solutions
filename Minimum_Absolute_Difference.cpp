#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr)
    {
        std::vector<std::vector<int>> res;
        std::sort(arr.begin(), arr.end());

        int minAbs = INT_MAX;

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            int diff = (arr[i + 1] - arr[i]);

            if (diff < minAbs)
            {
                minAbs = diff;
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
            }
            else if (diff == minAbs)
            {
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec = {4, 2, 1, 3};
    for (const auto &v : s1.minimumAbsDifference(vec))
    {
        for (const auto &n : v)
        {
            std::cout << n << " ";
        }
    }
    std::cout << std::endl;

    vec = {1, 3, 6, 10, 15};
    for (const auto &v : s1.minimumAbsDifference(vec))
    {
        for (const auto &n : v)
        {
            std::cout << n << " ";
        }
    }
    std::cout << std::endl;

    vec = {3, 8, -10, 23, 19, -4, -14, 27};
    for (const auto &v : s1.minimumAbsDifference(vec))
    {
        for (const auto &n : v)
        {
            std::cout << n << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}