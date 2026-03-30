#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

////////////////////////////////////////////////////////////

class Johnann
{
public:
    static std::vector<long long> john(long long n);
    static std::vector<long long> ann(long long n);
    static long long sumJohn(long long n);
    static long long sumAnn(long long n);
};

std::vector<long long> Johnann::john(long long n)
{
    std::vector<long long> a = {1};
    std::vector<long long> j = {0};

    for (long long i = 1; i < n; ++i)
    {
        long long t_john = j[i - 1];
        j.push_back(i - a[t_john]);

        long long t_ann = a[i - 1];
        a.push_back(i - j[t_ann]);
    }

    return j;
}

std::vector<long long> Johnann::ann(long long n)
{
    std::vector<long long> a = {1};
    std::vector<long long> j = {0};

    for (long long i = 1; i < n; ++i)
    {
        long long t_john = j[i - 1];
        j.push_back(i - a[t_john]);

        long long t_ann = a[i - 1];
        a.push_back(i - j[t_ann]);
    }

    return a;
}

long long Johnann::sumJohn(long long n)
{
    auto v = john(n);
    long long j_sum = std::accumulate(v.begin(), v.end(), 0LL);

    return j_sum;
}

long long Johnann::sumAnn(long long n)
{
    auto v = ann(n);
    long long a_sum = std::accumulate(v.begin(), v.end(), 0LL);

    return a_sum;
}

////////////////////////////////////////////////////////////

void testSumAnn(long long ans, long long sol)
{
    std::cout << ans << " ; " << sol << std::endl;
    assert(ans == (sol));
}
void testSumJohn(long long ans, long long sol)
{
    assert(ans == (sol));
}
void testann(std::vector<long long> ans, std::vector<long long> sol)
{
    assert(ans == (sol));
}
void testjohn(std::vector<long long> ans, std::vector<long long> sol)
{
    assert(ans == (sol));
}

int main()
{
    // sumAnn_Tests
    testSumAnn(Johnann::sumAnn(115), 4070);

    // sumJohn_Tests
    testSumJohn(Johnann::sumJohn(75), 1720);

    // ann_Tests
    testann(Johnann::ann(6), {1, 1, 2, 2, 3, 3});

    // john_Tests
    testann(Johnann::john(11), {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6});

    return 0;
}