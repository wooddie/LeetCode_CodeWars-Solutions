#include <iostream>
#include <vector>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        if (triangle.size() < 2)
            return triangle[0][0];

        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    Solution s1;

    std::vector<std::vector<int>> vec = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout << s1.minimumTotal(vec) << std::endl;

    vec = {{-10}};
    std::cout << s1.minimumTotal(vec) << std::endl;

    return 0;
}