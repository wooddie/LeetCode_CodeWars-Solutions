#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> freq1;
        std::unordered_map<int, int> freq2;

        for (const auto &n : nums1)
        {
            freq1[n]++;
        }
        for (const auto &n : nums2)
        {
            freq2[n]++;
        }

        std::vector<int> res;

        for (const auto &pair : freq1)
        {
            if (freq2.contains(pair.first))
            {
                int count = std::min(pair.second, freq2[pair.first]);

                while (count > 0)
                {
                    res.push_back(pair.first);
                    count--;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v1 = {1, 2, 2, 1};
    std::vector<int> v2 = {2, 2};
    for (const auto &n : s1.intersect(v1, v2))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v1 = {4, 9, 5};
    v2 = {9, 4, 9, 8, 4};
    for (const auto &n : s1.intersect(v1, v2))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}