#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

        for (int i = 0; i < s.length(); ++i)
        {
            if (!dp[i])
                continue;

            for (int j = i + 1; j <= s.length(); ++j)
            {
                std::string sub = s.substr(i, j - i);
                if (dict.count(sub))
                {
                    dp[j] = true;
                }
            }
        }

        return dp[s.length()];
    }
};

int main()
{
    Solution s1;

    std::string str = "leetcode";
    std::vector<std::string> vec = {"leet", "code"};
    std::cout << std::boolalpha << s1.wordBreak(str, vec) << std::endl;

    str = "applepenapple";
    vec = {"apple", "pen"};
    std::cout << std::boolalpha << s1.wordBreak(str, vec) << std::endl;

    str = "catsandog";
    vec = {"cats", "dog", "sand", "and", "cat"};
    std::cout << std::boolalpha << s1.wordBreak(str, vec) << std::endl;

    return 0;
}