#include <iostream>
#include <cassert>
#include <array>
#include <unordered_map>

int score(const std::array<unsigned, 5> &dice)
{
    int score = 0;
    std::unordered_map<int, int> map;

    for (const auto num : dice)
    {
        map[num]++;
    }

    for (auto &[number, count] : map)
    {
        if (count >= 3)
        {
            score += (number == 1) ? 1000 : number * 100;
        }

        int rem = count % 3;

        if (number == 1)
        {
            score += rem * 100;
        }
        else if (number == 5)
        {
            score += rem * 50;
        }
    }

    return score;
}

int main()
{
    // should_value_this_as_worthless
    std::array<unsigned, 5> dice = {2, 3, 4, 6, 2};
    assert(score(dice) == (0));

    // should_value_this_triplet_correctly
    dice = {4, 4, 4, 3, 3};
    assert(score(dice) == (400));

    // should_value_this_mixed_set_correctly
    dice = {2, 4, 4, 5, 4};
    assert(score(dice) == (450));

    return 0;
}