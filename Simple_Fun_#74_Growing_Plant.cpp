#include <iostream>
#include <cassert>

int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
    int day = 1;
    int speed = upSpeed;

    while (speed < desiredHeight)
    {
        speed -= downSpeed;
        speed += upSpeed;
        day++;
    }

    return day;
}

void doTest(int upSpeed, int downSpeed, int desiredHeight, int expected)
{
    assert(growingPlant(upSpeed, downSpeed, desiredHeight) == (expected));
}

int main()
{
    doTest(100, 10, 910, 10);
    doTest(10, 9, 4, 1);

    return 0;
}