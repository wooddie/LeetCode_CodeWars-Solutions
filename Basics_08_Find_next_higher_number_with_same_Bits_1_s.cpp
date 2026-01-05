#include <iostream>
#include <cassert>
#include <bit>

int nextHigher(int value)
{
    int count = __builtin_popcount(value);
    bool flag = true;
    int num = value;

    while (flag)
    {
        num++;

        if (count == __builtin_popcount(num))
        {
            flag = false;
        }
    }

    return num;
}

int main()
{
    assert(nextHigher(128) == (256));
    assert(nextHigher(1) == (2));
    assert(nextHigher(1022) == (1279));
    assert(nextHigher(127) == (191));
    assert(nextHigher(1253343) == (1253359));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}