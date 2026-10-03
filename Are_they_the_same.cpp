#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Same
{
public:
    static bool comp(std::vector<int> &a, std::vector<int> &b)
    {
        if (a.size() != b.size())
            return false;

        std::unordered_map<int, int> b_count;
        for (int val : b)
        {
            b_count[val]++;
        }

        for (int val : a)
        {
            int squared = val * val;

            if (b_count[squared] == 0)
            {
                return false;
            }
            b_count[squared]--;
        }

        return true;
    }
};

void dotest(std::vector<int> a, std::vector<int> b, bool sol)
{
    bool ans = Same::comp(a, b);
    assert(ans == (sol));
}

int main()
{
    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    dotest(a, b, true);
    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
    dotest(a, b, false);

    return 0;
}