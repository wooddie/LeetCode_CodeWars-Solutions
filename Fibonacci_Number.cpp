#include <iostream>

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};

int main()
{
    Solution s1;

    std::cout << s1.fib(2) << std::endl;
    std::cout << s1.fib(3) << std::endl;
    std::cout << s1.fib(4) << std::endl;

    return 0;
}