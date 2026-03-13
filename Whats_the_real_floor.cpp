#include <iostream>
#include <cassert>

int getRealFloor(int f)
{
    if (f < 0)
        return f;
    else if (f < 13 && f > 0)
        return f - 1;

    return f - 2;
}

int main()
{
    assert(getRealFloor(1) == (0));
    assert(getRealFloor(5) == (4));
    assert(getRealFloor(15) == (13));

    return 0;
}