#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
public:
    int maxDistance(std::vector<int> &colors)
    {
        int start = 0;
        int end = colors.size() - 1;
        int maxDist = 0;

        if (colors[start] != colors[end])
        {
            return end;
        }

        for (int i = colors.size() - 1; i >= 1; --i)
        {
            if (colors[i] != colors[start])
            {
                maxDist = std::max(maxDist, abs(start - i));
                break;
            }
        }

        for (int i = 0; i < colors.size() - 1; ++i)
        {
            if (colors[i] != colors[end])
            {
                maxDist = std::max(maxDist, abs(end - i));
                break;
            }
        }

        return maxDist;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {1, 1, 1, 6, 1, 1, 1};
    std::cout << s1.maxDistance(v) << std::endl; // 3

    v = {1, 8, 3, 8, 3};
    std::cout << s1.maxDistance(v) << std::endl; // 4

    v = {0, 1};
    std::cout << s1.maxDistance(v) << std::endl; // 1

    return 0;
}