#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

std::vector<int> seqToOne(int n)
{
    std::vector<int> result;

    if (n > 1)
    {
        for (int i = n; i >= 1; i--)
            result.push_back(i);
    }
    else
    {
        for (int i = n; i <= 1; i++)
            result.push_back(i);
    }

    return result;
}

int main()
{
    assert((seqToOne(5) == std::vector<int>{5, 4, 3, 2, 1}));
    assert((seqToOne(-1) == std::vector<int>{-1, 0, 1}));

    return 0;
}