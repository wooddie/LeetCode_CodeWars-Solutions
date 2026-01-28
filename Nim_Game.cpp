#include <iostream>

class Solution
{
public:
    bool canWinNim(int n)
    {
        return (n % 4 == 0) ? false : true;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.canWinNim(4) << std::endl;
    std::cout << std::boolalpha << s1.canWinNim(1) << std::endl;
    std::cout << std::boolalpha << s1.canWinNim(2) << std::endl;

    return 0;
}