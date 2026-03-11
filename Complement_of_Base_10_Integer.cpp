#include <iostream>

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;

        int mask = 1;

        while (mask < n)
        {
            mask = (mask << 1) | 1;
        }

        return n ^ mask;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.bitwiseComplement(5) << std::endl;
    std::cout << s1.bitwiseComplement(7) << std::endl;
    std::cout << s1.bitwiseComplement(10) << std::endl;

    return 0;
}