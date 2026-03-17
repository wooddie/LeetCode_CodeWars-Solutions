#include <iostream>
#include <cassert>
#include <cmath>

int minimumPerimeter(int area)
{

    for (int i = sqrt(area); i >= 1; --i)
    {
        if (area % i == 0)
        {
            return 2 * (i + (area / i));
        }
    }

    return -1;
}

void dotest(int a, int p)
{
    assert(minimumPerimeter(a) == p);
}

int main()
{
    dotest(45, 28);
    dotest(30, 22);
    dotest(81, 36);
    dotest(89, 180);

    return 0;
}