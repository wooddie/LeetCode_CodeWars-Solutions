#include <iostream>
#include <cassert>
#include <utility>
#include <vector>

std::pair<int, int> min_max(const std::vector<int> &arr)
{
    int minElement = *std::min_element(arr.begin(), arr.end());
    int maxElement = *std::max_element(arr.begin(), arr.end());

    return {minElement, maxElement};
}

int main()
{
    // one_element
    assert(min_max({5}) == (std::pair{5, 5}) && ("Incorrect outut for min_max({ 5 }):"));

    // two_elements
    assert(min_max({5, 2334454}) == (std::pair{5, 2334454}) && ("Incorrect outut for min_max({ 5, 2334454 }):"));
    assert(min_max({2334454, 5}) == (std::pair{5, 2334454}) && ("Incorrect outut for min_max({ 2334454, 5 }):"));

    // more_than_two_elements
    assert(min_max({1, 2, 3, 4, 5}) == (std::pair{1, 5}) && ("Incorrect outut for min_max({ 1, 2, 3, 4, 5 }):"));
    assert(min_max({-93, 0, 1, 100, -94, 8}) == (std::pair{-94, 100}) && ("Incorrect outut for min_max({ -93, 0, 1, 100, -94, 8 }):"));

    return 0;
}