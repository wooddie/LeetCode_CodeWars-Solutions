#include <iostream>
#include <cassert>
#include <stdint.h>

int digits(uint64_t n)
{
    int count = 0;
    std::string num = std::to_string(n);

    for (size_t i = 0; i < num.size(); ++i)
    {
        if (std::isdigit(num[i]))
            ++count;
    }

    return count;
}

int main()
{
    assert(digits(5ull) == (1));
    assert(digits(12345ull) == (5));
    assert(digits(9876543210ull) == (10));

    return 0;
}