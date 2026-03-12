#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<int> min_value(const std::vector<int> &arr, std::size_t n)
{
    if (n == 1)
    {
        return arr;
    }

    std::vector<int> result;

    for (size_t i = 0; i <= arr.size() - n; ++i)
    {
        int minElement = *std::min_element(arr.begin() + i, arr.begin() + i + n);

        result.push_back(minElement);
    }

    return result;
}

int main()
{
    // n_equals_1
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 1) == (std::vector{1, -2, 3, -4, 5, -6, 7, 8}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 1):"));

    // n_between_1_and_length
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 2) == (std::vector{-2, -2, -4, -4, -6, -6, 7}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 2):"));
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 3) == (std::vector{-2, -4, -4, -6, -6, -6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 3):"));
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 4) == (std::vector{-4, -4, -6, -6, -6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 4):"));
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 5) == (std::vector{-4, -6, -6, -6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 5):"));
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 6) == (std::vector{-6, -6, -6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 6):"));
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 7) == (std::vector{-6, -6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 7):"));

    // n_equals_length
    assert(min_value({1, -2, 3, -4, 5, -6, 7, 8}, 8) == (std::vector{-6}) && ("Incorrect output for min_value({ 1, -2, 3, -4, 5, -6, 7, 8 }, 8):"));

    return 0;
}