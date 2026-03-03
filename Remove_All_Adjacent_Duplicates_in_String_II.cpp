#include <iostream>
#include <string>

class Solution
{
public:
    std::string removeDuplicates(std::string s, int k)
    {
        std::vector<std::pair<char, int>> st;

        for (char c : s)
        {
            if (!st.empty() && st.back().first == c)
            {
                st.back().second++;
            }
            else
            {
                st.push_back({c, 1});
            }

            if (st.back().second == k)
            {
                st.pop_back();
            }
        }

        std::string res = "";
        for (auto &p : st)
        {
            res.append(p.second, p.first);
        }
        return res;
    }
};

int main()
{
    Solution s1;

    std::cout << s1.removeDuplicates("abcd", 2) << std::endl;
    std::cout << s1.removeDuplicates("deeedbbcccbdaa", 3) << std::endl;
    std::cout << s1.removeDuplicates("pbbcggttciiippooaais", 2) << std::endl;

    return 0;
}