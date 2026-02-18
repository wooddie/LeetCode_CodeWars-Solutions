#include <iostream>
#include <cassert>
#include <vector>

using ull = unsigned long long;

ull exp_sum(unsigned int n)
{
    std::vector<ull> dp(n + 1, 0);

    dp[0] = 1;

    for (ull i = 1; i <= n; ++i)
    {
        for (ull j = i; j <= n; ++j)
        {
            dp[j] += dp[j - i];
        }
    }

    return dp.back();
}

int main()
{
    assert(exp_sum(1) == (1));
    assert(exp_sum(2) == (2));
    assert(exp_sum(3) == (3));
    assert(exp_sum(4) == (5));
    assert(exp_sum(5) == (7));
    assert(exp_sum(10) == (42));

    return 0;
}