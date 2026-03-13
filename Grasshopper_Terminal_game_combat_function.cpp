#include <iostream>
#include <cassert>

int combat(int health, int damage)
{
    return ((health - damage) >= 0) ? health - damage : 0;
}

int main()
{
    assert(combat(100, 5) == (95));
    assert(combat(83, 16) == (67));
    assert(combat(20, 30) == (0));

    return 0;
}