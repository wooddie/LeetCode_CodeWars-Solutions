#include <iostream>
#include <cassert>
#include <vector>

using vec = std::vector<int>;

std::vector<int> menFromBoys(const std::vector<int> &values)
{
    std::vector<int> even;
    std::vector<int> odd;

    for (const auto &n : values)
    {
        if (n % 2 == 0)
        {
            even.push_back(n);
        }
        else
        {
            odd.push_back(n);
        }
    }

    std::sort(even.begin(), even.end());
    std::sort(odd.rbegin(), odd.rend());

    auto last_even = std::unique(even.begin(), even.end());
    auto last_odd = std::unique(odd.begin(), odd.end());
    even.erase(last_even, even.end());
    odd.erase(last_odd, odd.end());

    even.insert(even.end(), odd.begin(), odd.end());

    return even;
}

int main()
{
    // Only_Even
    assert(menFromBoys({26, -6, 52, -24, 90}) == (vec{-24, -6, 26, 52, 90}));

    // Only_Odd
    assert(menFromBoys({25, -5, 51, -25, 91}) == (vec{91, 51, 25, -5, -25}));

    // Check_Positive_Values
    assert(menFromBoys({7, 3, 14, 17}) == (vec{14, 17, 7, 3}));
    assert(menFromBoys({2, 43, 95, 90, 37}) == (vec{2, 90, 95, 43, 37}));
    assert(menFromBoys({20, 33, 50, 34, 43, 46}) == (vec{20, 34, 46, 50, 43, 33}));
    assert(menFromBoys({82, 91, 72, 76, 76, 100, 85}) == (vec{72, 76, 82, 100, 91, 85}));
    assert(menFromBoys({2, 15, 17, 15, 2, 10, 10, 17, 1, 1}) == (vec{2, 10, 17, 15, 1}));

    // Check_Negative_Values
    assert(menFromBoys({-32, -39, -35, -41}) == (vec{-32, -35, -39, -41}));
    assert(menFromBoys({-64, -71, -63, -66, -65}) == (vec{-66, -64, -63, -65, -71}));
    assert(menFromBoys({-94, -99, -100, -99, -96, -99}) == (vec{-100, -96, -94, -99}));
    assert(menFromBoys({-53, -26, -53, -27, -49, -51, -14}) == (vec{-26, -14, -27, -49, -51, -53}));
    assert(menFromBoys({-17, -45, -15, -33, -85, -56, -86, -30}) == (vec{-86, -56, -30, -15, -17, -33, -45, -85}));

    // Check_Mixed_Values
    assert(menFromBoys({12, 89, -38, -78}) == (vec{-78, -38, 12, 89}));
    assert(menFromBoys({2, -43, 95, -90, 37}) == (vec{-90, 2, 95, 37, -43}));
    assert(menFromBoys({82, -61, -87, -12, 21, 1}) == (vec{-12, 82, 21, 1, -61, -87}));
    assert(menFromBoys({63, -57, 76, -85, 88, 2, -28}) == (vec{-28, 2, 76, 88, 63, -57, -85}));
    assert(menFromBoys({49, 818, -282, 900, 928, 281, -282, -1}) == (vec{-282, 818, 900, 928, 281, 49, -1}));

    return 0;
}