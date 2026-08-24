#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> add(const std::vector<int> &arr)
{
    std::vector<int> result(arr.size());
    result[0] = arr[0];

    for (int i = 1; i < arr.size(); ++i)
    {
        result[i] = arr[i] + result[i - 1];
    }

    return result;
}

int main()
{
    //(edge_cases)
    assert(add({0}) == (std::vector{0}) && ("Incorrect output for add({ 0 }):"));
    assert(add({-33}) == (std::vector{-33}) && ("Incorrect output for add({ -33 }):"));
    assert(add({32, -9, 2, 0}) == (std::vector{32, 23, 25, 25}) && ("Incorrect output for add({ 32, -9, 2, 0 }):"));

    //(basic_cases)
    assert(add({1, 2, 3, 4, 5}) == (std::vector{1, 3, 6, 10, 15}) && ("Incorrect output for add({ 1, 2, 3, 4, 5 }):"));
    assert(add({2, 4, 6, 8, 10}) == (std::vector{2, 6, 12, 20, 30}) && ("Incorrect output for add({ 2, 4, 6, 8, 10 }):"));
    assert(add({1, 8, 27, 64, 125}) == (std::vector{1, 9, 36, 100, 225}) && ("Incorrect output for add({ 1, 8, 27, 64, 125 }):"));

    //(larger_cases)
    assert(add({9, 18, 27, 36, 45, 54}) == (std::vector{9, 27, 54, 90, 135, 189}) && ("Incorrect output for add({ 9, 18, 27, 36, 45, 54 }):"));
    assert(add({6, 12, 18, 24, 30, 36, 42}) == (std::vector{6, 18, 36, 60, 90, 126, 168}) && ("Incorrect output for add({ 6, 12, 18, 24, 30, 36, 42 }):"));
    assert(add({8, 16, 24, 32, 40, 48, 56, 64}) == (std::vector{8, 24, 48, 80, 120, 168, 224, 288}) && ("Incorrect output for add({ 8, 16, 24, 32, 40, 48, 56, 64 }):"));

    return 0;
}