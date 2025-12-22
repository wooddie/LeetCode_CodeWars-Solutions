#include <iostream>
#include <vector>
#include <cassert>

using vec = std::vector<int>;

int grow(std::vector<int> nums)
{
    int result = 1;

    for(const auto &n : nums)
    {
        result *= n;
    }

    return result;
}

int main()
{
    assert(grow(vec{1, 2, 3}) == (6));
    assert(grow(vec{4, 1, 1, 1, 4}) == (16));
    assert(grow(vec{2, 2, 2, 2, 2, 2}) == (64));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}