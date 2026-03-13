#include <iostream>
#include <cassert>
#include <string>

std::string solve(const std::string &str)
{
    if (str.empty())
        return "";

    int lower = 0;
    int upper = 0;

    for (const auto &c : str)
    {
        if (std::islower(c))
        {
            lower++;
        }
        else if (std::isupper(c))
        {
            upper++;
        }
    }

    std::string result = str;

    if (lower >= upper)
    {
        for (char &c : result)
        {
            c = std::tolower((unsigned char)c);
        }
    }
    else if (upper > lower)
    {
        for (char &c : result)
        {
            c = std::toupper((unsigned char)c);
        }
    }

    return result;
}

int main()
{
    assert(solve("code") == ("code"));
    assert(solve("CODe") == ("CODE"));
    assert(solve("COde") == ("code"));
    assert(solve("Code") == ("code"));
    assert(solve("") == (""));

    return 0;
}