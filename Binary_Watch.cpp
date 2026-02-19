#include <iostream>
#include <vector>
#include <string>
#include <bit>

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn > 8)
            return {};

        std::vector<std::string> result;

        for (unsigned int hours = 0; hours <= 11; ++hours)
        {
            for (unsigned int minutes = 0; minutes <= 59; ++minutes)
            {
                if (std::popcount(hours) + std::popcount(minutes) == turnedOn)
                {
                    result.push_back(std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes));
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s1;

    for (const auto &s : s1.readBinaryWatch(1))
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    for (const auto &s : s1.readBinaryWatch(9))
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}