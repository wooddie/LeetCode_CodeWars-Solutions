#include <utility>
#include <vector>
#include <cstddef>
#include <cassert>

std::pair<std::size_t, std::size_t> mineLocation(
    const std::vector<std::vector<int>> &field)
{

    for (size_t i = 0; i < field.size(); ++i)
    {
        for (size_t j = 0; j < field.size(); ++j)
        {
            if (field[i][j] == 1)
            {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

int main()
{
    assert(
        mineLocation(
            {
                {1, 0},
                {0, 0},
            }) == (std::pair<std::size_t, std::size_t>(0, 0)));

    assert(
        mineLocation(
            {
                {0, 0, 0},
                {0, 0, 1},
                {0, 0, 0},
            }) == (std::pair<std::size_t, std::size_t>(1, 2)));

    assert(
        mineLocation(
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 0},
            }) == (std::pair<std::size_t, std::size_t>(3, 1)));

    return 0;
}