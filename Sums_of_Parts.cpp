#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

using V = std::vector<unsigned long long>;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long> &ls)
{
    if (ls.empty())
        return {};

    std::vector<unsigned long long> result;
    result.reserve(ls.size());

    unsigned long long current_sum = std::accumulate(ls.begin(), ls.end(), 0ULL);

    for (size_t i = 0; i < ls.size(); ++i)
    {
        result.push_back(current_sum);
        current_sum -= ls[i];
    }

    result.push_back(0);

    return result;
}

int main()
{
    assert(partsSum({0, 1, 3, 6, 10}) == (V{20, 20, 19, 16, 10, 0}));
    assert(partsSum({1, 2, 3, 4, 5, 6}) == (V{21, 20, 18, 15, 11, 6, 0}));
    assert(partsSum({744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358}) == (V{10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414, 9291270, 2581057, 2580168, 2579358, 0}));
    assert(partsSum({30350, 76431, 156228, 78043, 98977, 80169, 32457, 182875, 162323, 17508, 57971, 171907}) == (V{1145239, 1114889, 1038458, 882230, 804187, 705210, 625041, 592584, 409709, 247386, 229878, 171907, 0}));
    assert(partsSum({158077, 143494, 196531, 26272, 35656, 68756, 109861, 36958, 83895, 134127, 81618, 193758, 143422}) == (V{1412425, 1254348, 1110854, 914323, 888051, 852395, 783639, 673778, 636820, 552925, 418798, 337180, 143422, 0}));

    return 0;
}