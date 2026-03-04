#include <iostream>
#include <vector>

class Solution
{
public:
    int numSpecial(std::vector<std::vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        std::vector<int> row(m, 0);
        std::vector<int> col(n, 0);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s1;

    std::vector<std::vector<int>> vec = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    std::cout << s1.numSpecial(vec) << std::endl;

    vec = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::cout << s1.numSpecial(vec) << std::endl;

    return 0;
}