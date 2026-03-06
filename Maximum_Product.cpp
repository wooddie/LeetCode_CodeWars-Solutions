#include <iostream>
#include <cassert>
#include <vector>

int adjacentElementsProduct(std::vector<int> inputArray)
{
    int maxProduct = inputArray[0] * inputArray[1];

    for (int i = 1; i < inputArray.size() - 1; ++i)
    {
        maxProduct = std::max(maxProduct, inputArray[i] * inputArray[i + 1]);
    }

    return maxProduct;
}

int main()
{
    // Positive__Numbers
    assert(adjacentElementsProduct({5, 8}) == (40));
    assert(adjacentElementsProduct({1, 2, 3}) == (6));
    assert(adjacentElementsProduct({1, 5, 10, 9}) == (90));
    assert(adjacentElementsProduct({5, 1, 2, 3, 1, 4}) == (6));
    assert(adjacentElementsProduct({4, 12, 3, 1, 5}) == (48));

    // MiXed_Values
    assert(adjacentElementsProduct({3, 6, -2, -5, 7, 3}) == (21));
    assert(adjacentElementsProduct({9, 5, 10, 2, 24, -1, -48}) == (50));
    assert(adjacentElementsProduct({5, 6, -4, 2, 3, 2, -23}) == (30));
    assert(adjacentElementsProduct({-23, 4, -5, 99, -27, 329, -2, 7, -921}) == (-14));

    // Containg_Zeroes
    assert(adjacentElementsProduct({1, 0, 1, 0, 1000}) == (0));
    assert(adjacentElementsProduct({1, 2, 3, 0}) == (6));

    return 0;
}