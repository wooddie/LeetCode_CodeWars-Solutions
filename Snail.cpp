#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    std::vector<int> res;

    if (snail_map.empty() || snail_map[0].empty())
        return {};

    int top = 0;
    int left = 0;
    int bottom = static_cast<int>(snail_map.size()) - 1;
    int right = static_cast<int>(snail_map[0].size()) - 1;

    while (top <= bottom && left <= right)
    {
        // 1. Двигаемся ВПРАВО (строка top, меняется i)
        for (int i = left; i <= right; ++i)
        {
            res.push_back(snail_map[top][i]);
        }
        top++; // Схлопнули верхнюю границу

        // 2. Двигаемся ВНИЗ (столбец right, меняется i)
        for (int i = top; i <= bottom; ++i)
        {
            res.push_back(snail_map[i][right]);
        }
        right--; // Схлопнули правую границу

        // Проверка, чтобы не пройтись по одной и той же строке дважды (для неквадратных матриц)
        if (top <= bottom)
        {
            // 3. Двигаемся ВЛЕВО (строка bottom, меняется i)
            for (int i = right; i >= left; --i)
            {
                res.push_back(snail_map[bottom][i]);
            }
            bottom--; // Схлопнули нижнюю границу
        }

        if (left <= right)
        {
            // 4. Двигаемся ВВЕРХ (столбец left, меняется i)
            for (int i = bottom; i >= top; --i)
            {
                res.push_back(snail_map[i][left]);
            }
            left++; // Схлопнули левую границу
        }
    }

    return res;
}

int main()
{
    std::vector<std::vector<int>> v;
    std::vector<int> expected;

    v = {{}};
    expected = {};
    assert(snail(v) == (expected));

    v = {{1}};
    expected = {1};
    assert(snail(v) == (expected));

    v = {{1, 2}, {4, 3}};
    expected = {1, 2, 3, 4};
    assert(snail(v) == (expected));

    v = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(snail(v) == (expected));

    v = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    assert(snail(v) == (expected));

    return 0;
}