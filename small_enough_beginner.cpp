#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool small_enough(std::vector<int> arr, int limit)
{
    if (arr.empty())
    {
        return false;
    }

    std::sort(arr.begin(), arr.end());

    if (arr[arr.size() - 1] > limit)
    {
        return false;
    }

    return true;
}

int main()
{
    assert(small_enough(std::vector<int>{66, 101}, 200) == (true));

    assert(small_enough(std::vector<int>{78, 117, 110, 99, 104, 117, 107, 115}, 100) == (false));

    assert(small_enough(std::vector<int>{101, 45, 75, 105, 99, 107}, 107) == (true));

    assert(small_enough(std::vector<int>{80, 117, 115, 104, 45, 85, 112, 115}, 120) == (true));

    assert(small_enough(std::vector<int>{1, 1, 1, 1, 1, 2}, 1) == (false));

    assert(small_enough(std::vector<int>{78, 33, 22, 44, 88, 9, 6}, 87) == (false));

    assert(small_enough(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10) == (true));

    assert(small_enough(std::vector<int>{12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12}, 12) == (true));

    return 0;
}