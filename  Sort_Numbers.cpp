#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> solution(std::vector<int> nums)
{
    if (nums.empty())
    {
        return {};
    }

    bool swapped;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        swapped = false;

        for (size_t j = 0; j < nums.size() - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }

    return nums;
}

int main()
{
    typedef std::vector<int> v;

    assert(solution({1, 2, 3, 10, 5}) == (v{1, 2, 3, 5, 10}));
    assert(solution({}) == (v{}));
    assert(solution({20, 2, 10}) == (v{2, 10, 20}));
    assert(solution({2, 20, 10}) == (v{2, 10, 20}));

    return 0;
}