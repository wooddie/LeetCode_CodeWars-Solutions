#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<int> wordValue(std::vector<std::string> arr)
{
    std::vector<int> result;

    for (size_t i = 0; i < arr.size(); ++i)
    {
        int count = 0;

        for (auto c : arr[i])
        {
            if (std::isalpha(static_cast<unsigned char>(c)))
            {
                count += (c - 'a') + 1;
            }
        }

        result.push_back(count * (i + 1));
    }

    return result;
}

int main()
{
    assert(wordValue(std::vector<std::string>{"abc", "abc abc"}) == (std::vector<int>{6, 24}));
    assert(wordValue(std::vector<std::string>{"codewars", "abc", "xyz"}) == (std::vector<int>{88, 12, 225}));
    assert(wordValue(std::vector<std::string>{"abcdefghijklmnopqrstuvwxyz", "stamford bridge", "haskellers"}) == (std::vector<int>{351, 282, 330}));

    return 0;
}