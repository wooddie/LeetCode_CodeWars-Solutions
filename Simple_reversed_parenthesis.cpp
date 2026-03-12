#include <iostream>
#include <cassert>
#include <string>

int solve(std::string s)
{
    if (s.length() % 2 != 0)
        return -1;

    int open = 0;
    int close = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            open++;
        }
        else
        {
            if (open > 0)
            {
                open--;
            }
            else
            {
                close++;
            }
        }
    }

    return (open + 1) / 2 + (close + 1) / 2;
}

int main()
{
    assert(solve(")()(") == (2));
    assert(solve("((()") == (1));
    assert(solve("(((") == (-1));
    assert(solve("())(((") == (3));
    assert(solve("())()))))()()(") == (4));

    return 0;
}