#include <iostream>
#include <cassert>
#include <vector>

int nthSmallest(const std::vector<std::vector<int>> &arr, int n)
{
    std::vector<int> list;

    for (const auto &a : arr)
    {
        for (const auto &e : a)
        {
            list.push_back(e);
        }
    }

    std::sort(list.begin(), list.end());

    return list[n - 1];
}

int main()
{
    assert(nthSmallest({{1, 5}, {2}, {4, 8, 9}}, 4) == 5);

    std::cout << "all tests passed!" << std::endl;

    return 0;
}
