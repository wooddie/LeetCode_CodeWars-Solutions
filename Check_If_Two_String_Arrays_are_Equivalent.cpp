#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool arrayStringsAreEqual(std::vector<std::string> &word1, std::vector<std::string> &word2)
    {
        std::string s1;
        std::string s2;

        if (word1.size() > 1)
        {
            for (std::string &str : word1)
            {
                s1 += str;
            }
        }
        else
        {
            s1 = word1[0];
        }

        if (word2.size() > 1)
        {
            for (std::string &str : word2)
            {
                s2 += str;
            }
        }
        else
        {
            s2 = word2[0];
        }

        if (s1 == s2)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution s1;

    std::vector<std::string> v = {"ab", "c"};
    std::vector<std::string> v1 = {"a", "bc"};
    std::cout << std::boolalpha << s1.arrayStringsAreEqual(v, v1) << std::endl;

    v = {"a", "cb"};
    v1 = {"ab", "c"};
    std::cout << std::boolalpha << s1.arrayStringsAreEqual(v, v1) << std::endl;

    v = {"abc", "d", "defg"};
    v1 = {"abcddefg"};
    std::cout << std::boolalpha << s1.arrayStringsAreEqual(v, v1) << std::endl;

    return 0;
}