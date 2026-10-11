#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

std::string latestClock(int a, int b, int c, int d)
{
    std::vector<int> digits = {a, b, c, d};
    std::sort(digits.begin(), digits.end());

    std::string result;
    int max_total_minutes = -1;

    do
    {
        int hours = digits[0] * 10 + digits[1];
        int minutes = digits[2] * 10 + digits[3];

        if (hours <= 24 && minutes <= 59)
        {
            int total_minutes = hours * 60 + minutes;

            if (total_minutes > max_total_minutes)
            {
                max_total_minutes = total_minutes;

                result = std::to_string(digits[0]) + std::to_string(digits[1]) + ":" + std::to_string(digits[2]) + std::to_string(digits[3]);
            }
        }

    } while (std::next_permutation(digits.begin(), digits.end()));

    if (max_total_minutes == -1)
    {
        return "00:00";
    }

    return result;
}

int main()
{
    assert(latestClock(1, 9, 8, 3) == ("19:38") && ("latestClock(1, 9, 8, 3) returned incorrect answer"));

    assert(latestClock(9, 1, 2, 5) == ("21:59") && ("latestClock(9, 1, 2, 5) returned incorrect answer"));

    return 0;
}