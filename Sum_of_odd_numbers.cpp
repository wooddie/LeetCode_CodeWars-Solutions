#include <iostream>
#include <cassert>

long long rowSumOddNumbers(unsigned n)
{
    int k = n * (n - 1) + 1;
    long long sum = 0;

    for (unsigned i = 0; i < n; ++i)
    {
        sum += k + 2 * i;
    }

    return sum;
}

int main()
{
    std::cout << rowSumOddNumbers(1) << std::endl;
    std::cout << rowSumOddNumbers(42) << std::endl;
    // assert(rowSumOddNumbers(1) == (1));
    // assert(rowSumOddNumbers(42) == (74088));

    return 0;
}