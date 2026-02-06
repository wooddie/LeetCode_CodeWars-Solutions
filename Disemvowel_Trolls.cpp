#include <iostream>
#include <cassert>
#include <string>

std::string disemvowel(const std::string &str)
{
    std::string res;
    const std::string vowels = "aeiouAEIOU";

    for (char c : str)
    {
        if (vowels.find(c) == std::string::npos)
        {
            res.push_back(c);
        }
    }

    return res;
}

int main()
{
    assert(disemvowel("This website is for losers LOL!") == ("Ths wbst s fr lsrs LL!"));

    return 0;
}