#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

std::pair<int, int> reduceFraction(const std::pair<int, int> &fraction)
{
    int d = std::gcd(fraction.first, fraction.second);
    return {fraction.first / d, fraction.second / d};
}

int main()
{

    return 0;
}