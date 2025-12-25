#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        for (const auto &c : ransomNote)
        {
            auto it = magazine.find(c);

            if (it == std::string::npos)
            {
                return false;
            }

            magazine.erase(it, 1);
        }

        return true;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.canConstruct("a", "b") << std::endl;
    std::cout << std::boolalpha << s1.canConstruct("aa", "ab") << std::endl;
    std::cout << std::boolalpha << s1.canConstruct("aa", "aab") << std::endl;

    return 0;
}