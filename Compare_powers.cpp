#include <iostream>
#include <cassert>
#include <cmath>

int comparePowers(std::pair<long, long> n1, std::pair<long, long> n2)
{

    double val1 = n1.second * std::log(n1.first);
    double val2 = n2.second * std::log(n2.first);

    if (val1 > val2)
    {
        return -1;
    }
    else if (val2 > val1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    // SmallerNumbers
    assert(comparePowers({2, 10}, {2, 15}) == (1));
    assert(comparePowers({1, 10}, {3, 10}) == (1));
    assert(comparePowers({2, 4}, {4, 2}) == (0));
    assert(comparePowers({3, 9}, {1, 6}) == (-1));
    assert(comparePowers({1, 10}, {1, 15}) == (0));

    // BiggerNumbers
    assert(comparePowers({2, 100}, {2, 150}) == (1));
    assert(comparePowers({1, 100}, {3, 100}) == (1));
    assert(comparePowers({2, 100}, {2, 100}) == (0));
    assert(comparePowers({34, 98}, {51, 67}) == (-1));
    assert(comparePowers({1024, 97}, {1024, 81}) == (-1));

    return 0;
}