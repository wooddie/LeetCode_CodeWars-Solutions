#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int var = 4;

    bool isBadVersion(int version)
    {
        if (version == var)
        {
            return true;
        }

        return false;
    }

    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.firstBadVersion(5) << std::endl;
    std::cout << s1.firstBadVersion(1) << std::endl;

    return 0;
}