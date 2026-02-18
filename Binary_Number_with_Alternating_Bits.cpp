#include <iostream>

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        std::vector<int> bits;

        while (n > 0)
        {
            bits.push_back(n % 2);
            n /= 2;
        }

        std::reverse(bits.begin(), bits.end());

        int prev = bits[0];

        for (int i = 1; i < bits.size(); ++i)
        {
            if (prev == bits[i])
            {
                return false;
            }

            prev = bits[i];
        }

        return true;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.hasAlternatingBits(5) << std::endl;
    std::cout << std::boolalpha << s1.hasAlternatingBits(7) << std::endl;
    std::cout << std::boolalpha << s1.hasAlternatingBits(11) << std::endl;

    return 0;
}