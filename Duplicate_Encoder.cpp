#include <iostream>
#include <cassert>
#include <unordered_map>
#include <string>

std::string duplicate_encoder(const std::string &word)
{
    std::unordered_map<char, int> freq;
    std::string res;

    for (const auto &c : word)
    {
        freq[std::tolower(c)]++;
    }

    for (const auto &ch : word)
    {
        if (freq[std::tolower(ch)] > 1)
        {
            res += ')';
        }
        else
        {
            res += '(';
        }
    }

    return res;
}

int main()
{
    assert(duplicate_encoder("din") == ("((("));
    assert(duplicate_encoder("recede") == ("()()()"));
    assert(duplicate_encoder("Success") == (")())())"));
    assert(duplicate_encoder("CodeWarrior") == ("()(((())())"));
    assert(duplicate_encoder("Supralapsarian") == (")()))()))))()("));
    assert(duplicate_encoder("(( @") == ("))(("));
    assert(duplicate_encoder(" ( ( )") == (")))))("));

    return 0;
}