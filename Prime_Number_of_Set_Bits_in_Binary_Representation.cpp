#include <iostream>
#include <string>
#include <bit>

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right)
    {
        int res = 0;

        for (int i = left; i <= right; ++i)
        {
            if(isPrime(__builtin_popcount(i)))
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.countPrimeSetBits(6, 10) << std::endl;
    std::cout << s1.countPrimeSetBits(10, 15) << std::endl;

    return 0;
}