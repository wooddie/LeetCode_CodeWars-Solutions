#include <iostream>
#include <numeric>
#include <cassert>
#include <utility>

class SumFractions
{
public:
    static std::pair<int, int> sumFracts(std::vector<std::vector<int>> &l);
};

std::pair<int, int> SumFractions::sumFracts(std::vector<std::vector<int>> &l)
{
    int d = 1;

    for (const auto &v : l)
    {
        d *= v[1];
    }

    int n = 0;

    for (const auto &v : l)
    {
        n += (d / v[1]) * v[0];
    }

    int divisior = std::gcd(n, d);

    return {(n / divisior), (d / divisior)};
};

void testequal(std::pair<int, int> ans, std::pair<int, int> sol)
{
    assert(ans == (sol));
}

int main()
{
    std::vector<std::vector<int>> a1 = {{1, 2}, {2, 9}, {3, 18}, {4, 24}, {6, 48}};
    testequal(SumFractions::sumFracts(a1), {85, 72});
    std::vector<std::vector<int>> a2 = {{1, 2}, {1, 3}, {1, 4}};
    testequal(SumFractions::sumFracts(a2), {13, 12});
    std::vector<std::vector<int>> a3 = {{1, 3}, {5, 3}};
    testequal(SumFractions::sumFracts(a3), {2, 1});
    std::vector<std::vector<int>> a4 = {};
    testequal(SumFractions::sumFracts(a4), {0, 1});

    std::cout << "all tests passed!" << std::endl;

    return 0;
}