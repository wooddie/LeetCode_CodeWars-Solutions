#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

int stray(std::vector<int> numbers)
{
    int unique_num = 0;

    for(const auto n : numbers)
    {
        unique_num ^= n;
    }

    return unique_num;
}

int main()
{
    assert(stray({1, 1, 2}) == 2);
    assert(stray({17, 17, 3, 17, 17, 17, 17}) == 3);

    return 0;
}