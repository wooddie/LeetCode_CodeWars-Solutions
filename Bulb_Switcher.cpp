#include <iostream>

class Solution
{
public:
    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
};

int main()
{
    Solution s1;

    std::cout << s1.bulbSwitch(3) << std::endl;
    std::cout << s1.bulbSwitch(0) << std::endl;
    std::cout << s1.bulbSwitch(1) << std::endl;

    return 0;
}