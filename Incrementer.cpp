#include <iostream>
#include <cassert>
#include <vector>
#include <random>

std::vector<int> incrementer(std::vector<int> nums)
{
    std::vector<int> res;

    for (int i = 0; i < nums.size(); ++i)
    {
        res.push_back((nums[i] + i + 1) % 10);
    }

    return res;
}

int main()
{
    std::vector<int> nums = {};
    std::vector<int> expected = {};
    assert(incrementer(nums) == (expected));
    nums = {1, 2, 3};
    expected = {2, 4, 6};
    assert(incrementer(nums) == (expected));
    nums = {4, 6, 7, 1, 3};
    expected = {5, 8, 0, 5, 8};
    assert(incrementer(nums) == (expected));
    nums = {3, 6, 9, 8, 9};
    expected = {4, 8, 2, 2, 4};
    assert(incrementer(nums) == (expected));
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9, 8};
    expected = {2, 4, 6, 8, 0, 2, 4, 6, 8, 9, 0, 1, 2, 2};
    assert(incrementer(nums) == (expected));

    return 0;
}