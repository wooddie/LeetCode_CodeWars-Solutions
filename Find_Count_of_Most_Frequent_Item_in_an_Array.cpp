#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

unsigned int most_frequent_item_count(const std::vector<int> &collection)
{
    if (collection.empty())
    {
        return 0;
    }

    std::unordered_map<unsigned int, unsigned int> freq;
    unsigned int most_freq = collection[0], max_cnt = 0;

    for (const auto n : collection)
    {
        if (++freq[n] > max_cnt)
        {
            max_cnt = freq[n];
            most_freq = n;
        }
    }

    return max_cnt;
}

int main()
{
    std::vector<int> collection = {3, -1, -1};
    assert(most_frequent_item_count(collection) == (2));
    collection = {3, -1, -1, -1, 2, 3, -1, 3, -1, 2, 4, 9, 3};
    assert(most_frequent_item_count(collection) == (5));
    collection = {};
    assert(most_frequent_item_count(collection) == (0));
    collection = {9};
    assert(most_frequent_item_count(collection) == (1));

    return 0;
}