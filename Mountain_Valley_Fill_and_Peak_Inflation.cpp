#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<int> valley_fill(std::vector<int> arr)
{
    if (arr.size() < 3)
        return arr;

    while (true)
    {
        bool was_changed = false;

        for (size_t i = 1; i < arr.size() - 1; ++i)
        {
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            {
                arr[i] = arr[i - 1] + arr[i + 1];
                was_changed = true;
                break;
            }
        }

        if (!was_changed)
        {
            break;
        }
    }

    return arr;
}

std::vector<int> peak_inflation(std::vector<int> arr)
{
    if (arr.size() < 3)
        return arr;

    while (true)
    {
        bool was_changed = false;

        for (size_t i = 1; i < arr.size() - 1; ++i)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                arr[i] = arr[i - 1] + arr[i + 1] + arr[i];
                was_changed = true;

                arr.erase(arr.begin() + i + 1);
                arr.erase(arr.begin() + i - 1);

                break;
            }
        }

        if (!was_changed)
        {
            break;
        }
    }

    return arr;
}

std::vector<int> mountain(const std::vector<int> &arr)
{
    std::vector<int> result = valley_fill(arr);

    return peak_inflation(result);
}

int main()
{
    //(Test1_Example1)
    std::vector<int> input = {5, 2, 6, 1, 4};
    std::vector<int> expected = {51};
    assert(mountain(input) == (expected));

    //(Test2_Example2)
    input = {7, 4, 3, 8, 7};
    expected = {38, 8, 7};
    assert(mountain(input) == (expected));

    //(Test3_Example3_FlatArray)
    input = {10, 10, 10};
    expected = {10, 10, 10};
    assert(mountain(input) == (expected));

    //(Test4_UserTraceExample)
    input = {7, 4, 3, 8, 7, 6, 2, 4, 4, 4, 4, 8, 9, 1};
    expected = {144, 17, 10, 4, 4, 4, 4, 18};
    assert(mountain(input) == (expected));

    //(Test5_SingleValleyToSinglePeak)
    input = {3, 1, 4};
    expected = {14};
    assert(mountain(input) == (expected));

    //(Test6_MultiValleyCascade)
    input = {10, 2, 8, 3, 9};
    expected = {89};
    assert(mountain(input) == (expected));

    //(Test7_WShapeMultiPeakCollapse)
    input = {10, 2, 8, 1, 9, 3, 11};
    expected = {203};
    assert(mountain(input) == (expected));

    //(Test8_DoublePeakCascade)
    input = {5, 1, 6, 6, 1, 5};
    expected = {22, 22};
    assert(mountain(input) == (expected));

    //(Test9_VShapeCompleteCollapse)
    input = {12, 3, 15};
    expected = {54};
    assert(mountain(input) == (expected));

    //(Test10_StrictMonotonicIncreasing)
    input = {1, 2, 3, 4, 5};
    expected = {1, 2, 3, 4, 5};
    assert(mountain(input) == (expected));

    return 0;
}