#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class Solution
{
public:
    std::vector<int> countFreq(const std::string &s)
    {
        std::vector<int> freq(26, 0);
        for (char c : s)
        {
            if (std::isalpha(c))
                freq[std::tolower(c) - 'a']++;
        }
        return freq;
    }

    std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string> &words)
    {
        std::vector<int> targetFreq = countFreq(licensePlate);
        std::string result = "";

        for (const std::string &w : words)
        {
            std::vector<int> wordFreq = countFreq(w);
            bool match = true;

            for (int i = 0; i < 26; ++i)
            {
                if (wordFreq[i] < targetFreq[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                if (result.empty() || w.size() < result.size())
                {
                    result = w;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s1;

    std::vector<std::string> vec = {"step", "steps", "stripe", "stepple"};
    std::cout << s1.shortestCompletingWord("1s3 PSt", vec) << std::endl;

    vec = {"looks", "pest", "stew", "show"};
    std::cout << s1.shortestCompletingWord("1s3 456", vec) << std::endl;

    return 0;
}