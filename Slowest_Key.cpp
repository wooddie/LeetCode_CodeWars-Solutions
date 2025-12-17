#include <iostream>
#include <vector>

class Solution
{
public:
    char slowestKey(std::vector<int> &releaseTimes, std::string keysPressed)
    {
        int maxDuration = releaseTimes[0];
        char resultKey = keysPressed[0];

        for (size_t i = 1; i < releaseTimes.size(); ++i)
        {
            int duration = releaseTimes[i] - releaseTimes[i - 1];

            if (duration > maxDuration || (duration == maxDuration && keysPressed[i] > resultKey))
            {
                maxDuration = duration;
                resultKey = keysPressed[i];
            }
        }

        return resultKey;
    }
};

int main()
{
    Solution s1;

    std::vector<int> v = {9, 29, 49, 50};
    std::cout << s1.slowestKey(v, "cbcd") << std::endl;

    v = {12, 23, 36, 46, 62};
    std::cout << s1.slowestKey(v, "spuda") << std::endl;

    return 0;
}