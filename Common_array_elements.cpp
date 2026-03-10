#include <iostream>
#include <cassert>
#include <vector>

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    int result = 0;
    size_t aIndex = 0;
    size_t bIndex = 0;
    size_t cIndex = 0;

    while (aIndex < a.size() && bIndex < b.size() && cIndex < c.size())
    {
        if (a[aIndex] == b[bIndex] && b[bIndex] == c[cIndex])
        {
            result += a[aIndex];
            aIndex++;
            bIndex++;
            cIndex++;
        }
        else
        {
            if (a[aIndex] < b[bIndex])
            {
                aIndex++;
            }
            else if (b[bIndex] < c[cIndex])
            {
                bIndex++;
            }
            else
            {
                cIndex++;
            }
        }
    }

    return result;
}

int main()
{
    assert(common(std::vector<int>{1, 2, 3}, std::vector<int>{5, 3, 2}, std::vector<int>{7, 3, 2}) == (5));
    assert(common(std::vector<int>{1, 2, 2, 3}, std::vector<int>{5, 3, 2, 2}, std::vector<int>{7, 3, 2, 2}) == (7));

    return 0;
}