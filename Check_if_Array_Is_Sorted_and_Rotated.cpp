#include <iostream>
#include <vector>

class Solution
{
public:
    bool check(std::vector<int> &nums)
    {
        int count = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                count++;
            }
        }

        return count <= 1;
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec = {3, 4, 5, 1, 2};
    std::cout << std::boolalpha << s1.check(vec) << std::endl;

    vec = {2, 1, 3, 4};
    std::cout << std::boolalpha << s1.check(vec) << std::endl;

    vec = {1, 2, 3};
    std::cout << std::boolalpha << s1.check(vec) << std::endl;

    return 0;
}