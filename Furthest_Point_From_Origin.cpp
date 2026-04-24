#include <iostream>
#include <string>

class Solution
{
public:
    int furthestDistanceFromOrigin(std::string moves)
    {
        int countR = 0;
        int countL = 0;
        int countBlank = 0;

        for (const auto &move : moves)
        {
            if (move == 'R')
            {
                countR++;
            }
            else if (move == 'L')
            {
                countL++;
            }
            else
            {
                countBlank++;
            }
        }

        return abs(countL - countR) + countBlank;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.furthestDistanceFromOrigin("L_RL__R") << std::endl;
    std::cout << s1.furthestDistanceFromOrigin("_R__LL_") << std::endl;
    std::cout << s1.furthestDistanceFromOrigin("_______") << std::endl;

    return 0;
}