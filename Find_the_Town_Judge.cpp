#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findJudge(int n, std::vector<std::vector<int>> &trust)
    {
        if (n == 1 && trust.empty())
        {
            return n;
        }

        std::unordered_map<int, int> list;

        for (const auto vec : trust)
        {
            list[vec[0]]--;
            list[vec[1]]++;
        }
        int val = n - 1;

        auto it = std::find_if(list.begin(), list.end(), [&val](const std::pair<int, int> &pair)
                               { return pair.second == val; });

        if (it != list.end())
        {
            return it->first;
        }

        return -1;
    }
};

int main()
{
    Solution s1;

    std::vector<std::vector<int>> vec = {{1, 2}};
    std::cout << s1.findJudge(2, vec) << std::endl;

    vec = {{1, 3}, {2, 3}};
    std::cout << s1.findJudge(3, vec) << std::endl;

    vec = {{1, 3}, {2, 3}, {3, 1}};
    std::cout << s1.findJudge(3, vec) << std::endl;

    return 0;
}