#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

int find_even_index(const std::vector<int> numbers)
{
    int right_sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int left_sum = 0;

    for (size_t i = 0; i != numbers.size(); ++i)
    {
        right_sum -= numbers[i];

        if (left_sum == right_sum)
        {
            return i;
        }

        left_sum += numbers[i];
    }

    return -1;
}

int main()
{
    std::vector<int> numbers{1, 2, 3, 4, 3, 2, 1};
    int expected = 3;
    assert(find_even_index(numbers) == (expected));

    numbers = {1, 100, 50, -51, 1, 1};
    expected = 1;
    assert(find_even_index(numbers) == (expected));

    numbers = {1, 2, 3, 4, 5, 6};
    expected = -1;
    assert(find_even_index(numbers) == (expected));

    numbers = {20, 10, 30, 10, 10, 15, 35};
    expected = 3;
    assert(find_even_index(numbers) == (expected));

    numbers = {20, 10, -80, 10, 10, 15, 35};
    expected = 0;
    assert(find_even_index(numbers) == (expected));

    numbers = {10, -80, 10, 10, 15, 35, 20};
    expected = 6;
    assert(find_even_index(numbers) == (expected));

    numbers = {0, 0, 0, 0, 0};
    expected = 0;
    assert(find_even_index(numbers) == (expected));

    numbers = {-1, -2, -3, -4, -3, -2, -1};
    expected = 3;
    assert(find_even_index(numbers) == (expected));

    return 0;
}