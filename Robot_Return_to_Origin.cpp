#include <iostream>
#include <string>

class Solution
{
public:
    bool judgeCircle(std::string moves)
    {
        int x = 0;
        int y = 0;

        for (const auto &c : moves)
        {
            if (c == 'U' || c == 'D')
            {
                if (c == 'U')
                {
                    x++;
                }
                else
                {
                    x--;
                }
            }
            else
            {
                if (c == 'R')
                {
                    y++;
                }
                else
                {
                    y--;
                }
            }
        }

        return (x == 0 && y == 0) ? true : false;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.judgeCircle("UD") << std::endl;
    std::cout << std::boolalpha << s1.judgeCircle("LL") << std::endl;

    return 0;
}