#include <iostream>
#include <cassert>

std::string solve(int n)
{

    std::string f0 = "0", f1 = "01";

    if (n < 2)
        return (n == 1) ? f1 : f0;

    for (int i = 2; i <= n; ++i)
    {
        std::string next_f = f1 + f0;
        f0 = f1;
        f1 = next_f;
    }

    return f1;
}

int main()
{
    assert(solve(0) == ("0"));
    assert(solve(1) == ("01"));
    assert(solve(2) == ("010"));
    assert(solve(3) == ("01001"));
    assert(solve(5) == ("0100101001001"));

    return 0;
}