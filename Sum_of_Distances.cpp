#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<long long> distance(std::vector<int> &nums)
    {
        std::unordered_map<int, std::pair<long long, long long>> mp;
        std::vector<long long> result(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            result[i] += (i * mp[num].first) - mp[num].second;

            mp[num].first++;
            mp[num].second += i;
        }

        mp.clear();

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int num = nums[i];
            result[i] += mp[num].second - (i * mp[num].first);

            mp[num].first++;
            mp[num].second += i;
        }

        return result;
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec = {1, 3, 1, 1, 2};
    for (const auto &num : s1.distance(vec))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    vec = {0, 5, 3};
    for (const auto &num : s1.distance(vec))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}