#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <array>

std::array<int, 2> two_oldest_ages(std::vector<int> ages)
{
    std::sort(ages.begin(), ages.end());

    return {ages[ages.size() - 2], ages[ages.size() - 1]};
}

std::array<int, 2> two_oldest_ages(std::vector<int> ages);

void do_test(const std::vector<int> &ages, const std::array<int, 2> &expected)
{
    assert(two_oldest_ages(ages) == (expected));
}

int main()
{
    do_test({1, 5, 87, 45, 8, 8}, {45, 87});
    do_test({6, 5, 83, 5, 3, 18}, {18, 83});

    return 0;
}