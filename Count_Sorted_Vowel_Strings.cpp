#include <iostream>

class Solution
{
public:
    long factorial(const int n)
    {
        long f = 1;
        int count = 1;

        for (int i = n; i > 0; --i)
            if (count < 5)
            {
                f *= i;
                count++;
            }
            else
            {
                break;
            }

        return f;
    }

    int countVowelStrings(int n)
    {
        return (factorial(n + 4) / factorial(4));
    }
};

int main()
{
    Solution s1;

    std::cout << s1.countVowelStrings(1) << std::endl;
    std::cout << s1.countVowelStrings(2) << std::endl;
    std::cout << s1.countVowelStrings(33) << std::endl;

    return 0;
}