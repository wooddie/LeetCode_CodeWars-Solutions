#include <iostream>
#include <cassert>
#include <cmath>

// Find a positive integer k such that gcd(a + k, b + k) is maximized.
// If there are multiple values of k that satisfy the condition above, return the smallest one.
long long get_k(long long a, long long b)
{
    long long d = llabs(b - a);
    if (d == 0)
        return 1;

    long long x = (d - (a % d)) % d;

    if (x == 0)
        return d;

    return x;
}

int main()
{
    assert(get_k(5, 7) == (1));
    assert(get_k(2, 10) == (6));
    assert(get_k(100, 200) == (100));
    assert(get_k(123, 456) == (210));

    return 0;
}