#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    std::string customSortString(std::string order, std::string s)
    {
        std::string res;
        std::unordered_map<char, int> freq;

        for (const auto &c : s)
        {
            freq[c]++;
        }

        for (int i = 0; i < order.size(); ++i)
        {
            int count = freq[order[i]];

            while (count > 0)
            {
                res.push_back(order[i]);
                --count;
            }

            freq[order[i]] = 0;
        }

        for (auto [ch, cnt] : freq)
        {
            while (cnt > 0)
            {
                res.push_back(ch);
                cnt--;
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.customSortString("cba", "abcd") << std::endl;
    std::cout << s1.customSortString("bcafg", "abcd") << std::endl;

    return 0;
}