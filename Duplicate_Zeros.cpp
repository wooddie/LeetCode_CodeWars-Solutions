#include <iostream>
#include <vector>

class Solution
{
public:
    void duplicateZeros(std::vector<int> &arr)
    {
        size_t originalSize = arr.size();

        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                i++;
            }
        }

        arr.resize(originalSize);

        for (const auto &n : arr)
        {
            std::cout << n << " ";
        }
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec = {1, 0, 2, 3, 0, 4, 5, 0};
    s1.duplicateZeros(vec);

    vec = {1, 2, 3};
    s1.duplicateZeros(vec);

    return 0;
}