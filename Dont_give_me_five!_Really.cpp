#include <iostream>
#include <cassert>
#include <string>
#include <vector>

#define ll long long

ll count(ll number)
{
    if (number < 0)
        return 0;

    std::string num = std::to_string(number);
    ll sum = 0;
    bool flag = true;

    std::vector<ll> p9(num.size() + 1, 1);
    for (size_t i = 1; i < p9.size(); ++i)
        p9[i] = p9[i - 1] * 9;

    for (int i = 0; i < static_cast<int>(num.size()); ++i)
    {
        ll dig = num[i] - '0';

        for (int j = 0; j < dig; ++j)
        {
            if (j == 5)
                continue;

            sum += p9[num.size() - i - 1];
        }

        if (dig == 5)
        {
            flag = false;
            break;
        }
    }

    if (flag)
        sum += 1;

    return sum;
}

ll dontGiveMeFive(ll start, ll end)
{
    if (start >= 0)
    {
        return count(end) - count(start - 1);
    }
    else if (end < 0)
    {
        return count(std::abs(start)) - count(std::abs(end) - 1);
    }
    else
    {
        return count(std::abs(start)) + count(end) - 1;
    }
}

int main()
{
    // (small_numbers)
    assert(dontGiveMeFive(-17, 9) == (24));
    assert(dontGiveMeFive(1, 9) == (8));
    assert(dontGiveMeFive(4, 17) == (12));
    assert(dontGiveMeFive(-17, -4) == (12));

    // (larger_numbers)
    assert(dontGiveMeFive(984, 4304) == (2449));
    assert(dontGiveMeFive(2313, 2317) == (4));
    assert(dontGiveMeFive(-4045, 2575) == (4819));
    assert(dontGiveMeFive(-4436, -1429) == (2194));

    // (huge_numbers)
    assert(dontGiveMeFive(40076, 2151514229639903569) == (326131553237897713));
    assert(dontGiveMeFive(-206981731, 2235756979031654521) == (340132150309630357));
    assert(dontGiveMeFive(-2490228783604515625, -2490228782196537011) == (520812180));
    assert(dontGiveMeFive(-9000000000000000000, 9000000000000000000) == (2401514164751985937));

    // (edge_cases)s
    assert(dontGiveMeFive(0, 1) == (2));
    assert(dontGiveMeFive(5, 15) == (9));
    assert(dontGiveMeFive(-5, 4) == (9));
    assert(dontGiveMeFive(51, 60) == (1));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}