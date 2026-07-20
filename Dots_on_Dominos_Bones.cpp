#include <iostream>
#include <cassert>

int dots_on_domino_bones(int number)
{
    return number * (number + 1) * (number + 2) / 2;
}

int main()
{
    assert(dots_on_domino_bones(2) == (12));
    assert(dots_on_domino_bones(5) == (105));
    assert(dots_on_domino_bones(13) == (1365));
    assert(dots_on_domino_bones(20) == (4620));
    assert(dots_on_domino_bones(33) == (19635));
    assert(dots_on_domino_bones(50) == (66300));
    assert(dots_on_domino_bones(137) == (1313967));
    assert(dots_on_domino_bones(198) == (3940200));

    return 0;
}