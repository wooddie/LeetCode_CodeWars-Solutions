#include <iostream>
#include <cassert>

int addFive(int num)
{
    int total = num + 5;
    return total;
}

int main()
{
    assert(addFive(5) == (10));
    assert(addFive(0) == (5));
    assert(addFive(-5) == (0));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}