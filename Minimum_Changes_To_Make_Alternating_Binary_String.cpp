#include <iostream>
#include <string>

class Solution
{
public:
    int minOperations(std::string s)
    {
        int miss = 0;

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (i % 2 == 0 && s[i] != '0')
            {
                miss++;
            }
            else if (i % 2 != 0 && s[i] != '1')
            {
                miss++;
            }
        }

        int sec = s.size() - miss;

        return (sec < miss) ? sec : miss;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.minOperations("0100") << std::endl;
    std::cout << s1.minOperations("10") << std::endl;
    std::cout << s1.minOperations("1111") << std::endl;

    return 0;
}