#include <iostream>

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int count = 0;

        for (int i = 1; i <= n; ++i)
        {
            int num = i;
            bool changed = false;
            bool invalid = false;

            while (num > 0)
            {
                int digit = num % 10;

                if (digit == 3 || digit == 4 || digit == 7)
                {
                    invalid = true;
                    break;
                }
                else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                {
                    changed = true;
                }

                num /= 10;
            }

            if (changed && !invalid)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.rotatedDigits(10) << std::endl;
    std::cout << s1.rotatedDigits(1) << std::endl;
    std::cout << s1.rotatedDigits(2) << std::endl;

    return 0;
}