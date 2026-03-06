#include <iostream>
#include <string>

class Solution
{
public:
    bool checkOnesSegment(std::string s)
    {
        auto it = s.find("01");

        if (it != std::string::npos)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.checkOnesSegment("1001") << std::endl;
    std::cout << std::boolalpha << s1.checkOnesSegment("110") << std::endl;

    return 0;
}