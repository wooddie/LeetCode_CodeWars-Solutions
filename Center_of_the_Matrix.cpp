#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

using opt_int_t = std::optional<int>;
using matrix_t = std::vector<std::vector<int>>;

opt_int_t center(const matrix_t &mat)
{
    if (mat.size() % 2 == 0 || mat.empty())
    {
        return std::nullopt;
    }

    size_t midRow = mat.size() / 2;

    if (mat[midRow].empty() || mat[midRow].size() % 2 == 0)
    {
        return std::nullopt;
    }

    size_t midElement = mat[midRow].size() / 2;

    return mat[midRow][midElement];
}

int main()
{

    assert(center({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) == (5) && ("Invalid result for [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ]"));
    assert(center({{1, 2, 3}, {4, 5, 6}}) == (std::nullopt) && ("Invalid result for [ [ 1, 2, 3 ], [ 4, 5, 6 ] ]"));

    return 0;
}