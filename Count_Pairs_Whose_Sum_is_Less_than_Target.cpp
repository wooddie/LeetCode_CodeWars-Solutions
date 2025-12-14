#include <iostream>
#include <vector>

class Solution
{
public:
    int countPairs(std::vector<int> &nums, int target)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] < target)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {-1, 1, 2, 3, 1};
    std::cout << s1.countPairs(v, 2) << std::endl;

    v = {-6, 2, 5, -2, -7, -1, 3};
    std::cout << s1.countPairs(v, -2) << std::endl;

    return 0;
}