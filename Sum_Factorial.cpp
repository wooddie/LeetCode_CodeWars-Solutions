#include <iostream>
#include <cassert>
#include <vector>

unsigned long long int sum_factorial(std::vector<int> vi)
{
    unsigned long long int result = 0;

    for (size_t i = 0; i < vi.size(); ++i)
    {
        unsigned long long int res = 1;

        for (int j = 2; j <= vi[i]; ++j)
        {
            res *= j;
        }

        result += res;
    }

    return result;
}

int main()
{
    // test1
    assert(sum_factorial({4, 6}) == (744));

    // test2
    assert(sum_factorial({4, 5, 1}) == (145));

    return 0;
}