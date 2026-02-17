#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values)
{
    for (const auto &n : values)
    {
        integers.erase(std::remove(integers.begin(), integers.end(), n), integers.end());
    }

    return integers;
}

int main()
{
    std::vector<int> integers, values, expected;

    integers = {1, 1, 2, 3, 1, 2, 3, 4};
    values = {1, 3};
    expected = {2, 2, 4};
    assert(remove_values(integers, values) == (expected));

    integers = {1, 1, 2, 3, 1, 2, 3, 4, 4, 3, 5, 6, 7, 2, 8};
    values = {1, 3, 4, 2};
    expected = {5, 6, 7, 8};
    assert(remove_values(integers, values) == (expected));

    integers = {8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2, 3};
    values = {2, 4, 3};
    expected = {8, 7, 6, 5, 1};
    assert(remove_values(integers, values) == (expected));

    return 0;
}