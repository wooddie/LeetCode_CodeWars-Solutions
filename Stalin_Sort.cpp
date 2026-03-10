#include <iostream>
#include <cassert>
#include <vector>

typedef std::vector<int> v;

void stalinSort(std::vector<int> &arr)
{
    if (arr.empty())
        return;

    int write = 1;

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] >= arr[write - 1])
        {
            arr[write] = arr[i];
            write++;
        }
        // else
        // {
        //     std::cout << "Элемент " << arr[i] << " расстрелян!" << std::endl;
        // }
    }

    arr.resize(write);

    for (const auto &n : arr)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // classic_purge
    v a = {3, 1, 4, 1, 5, 9, 2};
    stalinSort(a);
    assert(a == (v{3, 4, 5, 9}));

    // no_purge_needed
    a = {1, 2, 3};
    stalinSort(a);
    assert(a == (v{1, 2, 3}));

    // only_first_survives
    a = {5, 3, 1};
    stalinSort(a);
    assert(a == (v{5}));

    return 0;
}