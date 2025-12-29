#include <iostream>
#include <string>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        size_t i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.isSubsequence("abc", "ahbgdc") << std::endl;
    std::cout << std::boolalpha << s1.isSubsequence("axc", "ahbgdc") << std::endl;

    return 0;
}