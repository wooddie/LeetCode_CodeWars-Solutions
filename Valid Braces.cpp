#include <iostream>
#include <cassert>
#include <string>
#include <stack>

#define test(input, expected) assert(valid_braces(input) == (expected) && ("for input \"" input "\""))

bool valid_braces(const std::string &braces)
{
    std::stack<char> s;

    for (const char c : braces)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
                return false;

            char top = s.top();

            if (c == ')' && top != '(')
                return false;
            if (c == '}' && top != '{')
                return false;
            if (c == ']' && top != '[')
                return false;

            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    test("()", true);
    test("[(])", false);
    test("(((", false);

    return 0;
}