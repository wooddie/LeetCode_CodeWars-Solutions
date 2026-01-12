#include <iostream>
#include <cassert>
#include <algorithm>

unsigned add(unsigned x, unsigned y)
{
    std::string res;

    if (x == 0)
        return y;
    else if (y == 0)
        return x;

    while (x > 0 || y > 0)
    {
        int digX = x % 10;
        int digY = y % 10;

        res = std::to_string(digX + digY) + res;

        x /= 10;
        y /= 10;
    }

    return std::stoul(res);
}

int main()
{
    assert(add(2, 11) == (13));
    assert(add(0, 1) == (1));
    assert(add(0, 0) == (0));

    assert(add(16, 18) == (214));
    assert(add(122, 81) == (1103));
    assert(add(26, 39) == (515));

    return 0;
}