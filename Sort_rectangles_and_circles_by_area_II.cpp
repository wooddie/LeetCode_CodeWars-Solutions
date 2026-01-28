#include <iostream>
#include <cassert>
#include <utility>
#include <vector>

using vec_rect_circle = std::vector<std::pair<double, double>>;

double area(const std::pair<double, double> &p)
{
    if (p.second == 0)
        return M_PI * (p.first * p.first);
    else
        return p.first * p.second;
}

vec_rect_circle sort_by_area(vec_rect_circle v)
{
    std::sort(v.begin(), v.end(),
              [](const auto &a, const auto &b)
              {
                  return area(a) < area(b);
              });

    return v;
}

int main()
{
    assert(
        sort_by_area(vec_rect_circle{{4.23, 6.43}, {1.23, 0}, {3.444, 0}, {1.342, 3.212}}) == (vec_rect_circle{{1.342, 3.212}, {1.23, 0}, {4.23, 6.43}, {3.444, 0}}));

    assert(
        sort_by_area(vec_rect_circle{{2, 5}, {6, 0}}) == (vec_rect_circle{{2, 5}, {6, 0}}));

    assert(
        sort_by_area(vec_rect_circle{}) == (vec_rect_circle{}));

    return 0;
}