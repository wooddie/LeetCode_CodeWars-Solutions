#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            int count = 0;

            for (const auto &n : nums)
            {
                if (nums[i] > n)
                {
                    count++;
                }
            }

            res[i] = count;
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {8, 1, 2, 2, 3};
    for (const auto &n : s1.smallerNumbersThanCurrent(v))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v = {6, 5, 4, 8};
    for (const auto &n : s1.smallerNumbersThanCurrent(v))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v = {7, 7, 7, 7};
    for (const auto &n : s1.smallerNumbersThanCurrent(v))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}