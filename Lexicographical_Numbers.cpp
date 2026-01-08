#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> lexicalOrder(int n)
    {
        std::vector<int> res;

        int cur = 1;
        int count = 0;

        while (count < n)
        {
            res.push_back(cur);

            if ((cur * 10) <= n)
            {
                cur = cur * 10;
            }
            else
            {
                while (cur % 10 == 9 || (cur + 1) > n)
                {
                    cur = cur / 10;
                }
                cur = cur + 1;
            }

            count++;
        }

        return res;
    }
};

int main()
{
    Solution s1;

    for (const auto &n : s1.lexicalOrder(13))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (const auto &n : s1.lexicalOrder(2))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (const auto &n : s1.lexicalOrder(25))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}