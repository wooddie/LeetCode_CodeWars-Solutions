#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

long long calc(const std::vector<int> &x)
{
    auto it = std::min_element(x.begin(), x.end());
    int minElement = *it;

    return x.size() * minElement;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    assert(calc(v) == (5));
    v = {3, 4};
    assert(calc(v) == (6));

    return 0;
}