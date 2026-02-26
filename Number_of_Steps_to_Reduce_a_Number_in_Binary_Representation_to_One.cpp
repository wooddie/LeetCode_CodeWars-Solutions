#include <iostream>
#include <string>

class Solution
{
public:
    int numSteps(std::string s)
    {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--)
        {
            int current_bit = (s[i] - '0') + carry;

            if (current_bit == 1)
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps += 1;
            }
        }

        return steps + carry;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.numSteps("1101") << std::endl;
    std::cout << s1.numSteps("10") << std::endl;
    std::cout << s1.numSteps("1") << std::endl;

    return 0;
}