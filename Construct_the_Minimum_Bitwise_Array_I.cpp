#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
    std::vector<int> minBitwiseArray(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size(), 0);

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int target = nums[i];
            int num = -1;

            for (int j = target; j >= 0; --j)
            {
                if ((j | (j + 1)) == target)
                {
                    num = j;
                }
            }

            ans[i] = num;
        }

        return ans;
    }
};

void do_test(std::vector<int> input, std::vector<int> expected)
{
    Solution s1;

    assert(s1.minBitwiseArray(input) == expected && "The test case failed!");
}

int main()
{

    do_test({2, 3, 5, 7}, {-1, 1, 4, 3});
    do_test({11, 13, 31}, {9, 12, 15});

    return 0;
}