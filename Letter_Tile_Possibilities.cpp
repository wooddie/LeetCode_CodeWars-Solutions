#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int backtrack(std::unordered_map<char, int> &inver)
    {
        int count = 0;

        for (auto &pair : inver)
        {
            if (pair.second > 0)
            {
                count++;

                pair.second--;

                count += backtrack(inver);

                pair.second++;
            }
        }
        return count;
    }

    int numTilePossibilities(std::string tiles)
    {
        std::unordered_map<char, int> inver;

        for (const auto &n : tiles)
        {
            inver[n]++;
        }

        return backtrack(inver);
    }
};

int main()
{
    Solution s1;

    std::cout << s1.numTilePossibilities("AAB") << std::endl;
    std::cout << s1.numTilePossibilities("AAABBC") << std::endl;
    std::cout << s1.numTilePossibilities("V") << std::endl;

    return 0;
}