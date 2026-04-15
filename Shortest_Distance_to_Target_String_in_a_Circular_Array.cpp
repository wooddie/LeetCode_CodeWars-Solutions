#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Solution
{
public:
    int closestTarget(std::vector<std::string> &words, std::string target, int startIndex)
    {
        if (std::find(words.begin(), words.end(), target) == words.end())
        {
            return -1;
        }

        int n = words.size();
        int min_dist = n;

        for (int i = 0; i < words.size(); ++i)
        {
            std::string word = words[i];

            if (word == target)
            {
                int dir = std::abs(i - startIndex);
                int cir = n - dir;

                min_dist = std::min({min_dist, dir, cir});
            }
        }

        return min_dist;
    }
};

int main()
{
    Solution s1;

    std::vector<std::string> vec = {"hello", "i", "am", "leetcode", "hello"};
    std::cout << s1.closestTarget(vec, "hello", 1) << std::endl;

    vec = {"a", "b", "leetcode"};
    std::cout << s1.closestTarget(vec, "leetcode", 0) << std::endl;

    vec = {"i", "eat", "leetcode"};
    std::cout << s1.closestTarget(vec, "ate", 0) << std::endl;

    return 0;
}