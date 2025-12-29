#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> findErrorNums(std::vector<int> &nums)
    {
        std::vector<int> res;
        int duplicate = 0;
        int missing = 0;

        std::unordered_map<int, int> list;

        for (const auto &n : nums)
        {
            list[n]++;
        }

        for (int i = 1; i <= nums.size(); ++i)
        {
            if (list[i] == 2)
            {
                duplicate = i;
            }

            if (list[i] == 0)
            {
                missing = i;
            }
        }

        res.push_back(duplicate);
        res.push_back(missing);

        return res;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {1, 2, 2, 4};
    for (const auto &n : s1.findErrorNums(v))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v = {1, 1};
    for (const auto &n : s1.findErrorNums(v))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}