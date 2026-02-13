#include <iostream>
#include <vector>

class Solution
{
public:
    int maximumProduct(std::vector<int> &nums)
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        return std::max(
            nums[n - 1] * nums[n - 2] * nums[n - 3],
            nums[0] * nums[1] * nums[n - 1]);
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {1, 2, 3};
    std::cout << s1.maximumProduct(v) << std::endl;

    v = {1, 2, 3, 4};
    std::cout << s1.maximumProduct(v) << std::endl;

    v = {-1, -2, -3};
    std::cout << s1.maximumProduct(v) << std::endl;

    return 0;
}