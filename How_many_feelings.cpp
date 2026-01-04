#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

std::string countFeelings(const std::string& s,
                          const std::vector<std::string>& arr)
{
    std::unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    int count = 0;

    for (const auto& word : arr)
    {
        auto temp = freq;
        bool ok = true;

        for (char c : word)
        {
            if (--temp[c] < 0)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            count++;
    }

    return std::to_string(count) +
           (count == 1 ? " feeling." : " feelings.");
}


int main()
{
    assert(countFeelings("yliausoenvjw", {"anger", "awe", "joy", "love", "grief"}) == ("3 feelings."));
    assert(countFeelings("angerw", {"anger", "awe", "joy", "love", "grief"}) == ("2 feelings."));
    assert(countFeelings("griefgriefgrief", {"anger", "awe", "joy", "love", "grief"}) == ("1 feeling."));
    assert(countFeelings("abcdkasdfvkadf", {"desire", "joy", "shame", "longing", "fear"}) == ("0 feelings."));
    assert(countFeelings("abcdkasdfvkadflongin", {"desire", "joy", "shame", "longing", "fear"}) == ("0 feelings."));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}