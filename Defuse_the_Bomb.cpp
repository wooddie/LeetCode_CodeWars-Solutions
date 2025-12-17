#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> decrypt(std::vector<int> &code, int k)
    {
        std::vector<int> res;

        if (k > 0)
        {
            for (int i = 0; i < code.size(); ++i)
            {
                int count = 1;
                int sum = 0;

                while (count <= k)
                {
                    sum += code[(i + count) % code.size()];
                    count++;
                }

                res.push_back(sum);
            }
        }
        else if (k < 0)
        {
            int n = code.size();

            for (int i = 0; i < n; ++i)
            {
                int sum = 0;

                for (int count = 1; count <= -k; ++count)
                {
                    int idx = (i - count + n) % n;
                    sum += code[idx];
                }

                res.push_back(sum);
            }
        }
        else
        {
            for (int i = 0; i < code.size(); ++i)
            {
                res.push_back(0);
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {5, 7, 1, 4};
    for (const auto &n : s1.decrypt(v, 3))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v = {1, 2, 3, 4};
    for (const auto &n : s1.decrypt(v, 0))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v = {2, 4, 9, 3};
    for (const auto &n : s1.decrypt(v, -2))
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}