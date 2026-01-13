#include <iostream>
#include <cassert>
#include <string>
#include <map>

std::string outed(const std::map<std::string, int> &meet, const std::string &boss)
{
    int rating = 0;

    for (const auto &[key, value] : meet)
    {
        if (key == boss)
        {
            rating += value * 2;
        }
        else
        {
            rating += value;
        }
    }

    return ((double)rating / meet.size() > 5) ? "Nice Work Champ!" : "Get Out Now!";
}

int main()
{

    assert(outed({{"tim", 0}, {"jim", 2}, {"randy", 0}, {"sandy", 7}, {"andy", 0}, {"katie", 5}, {"laura", 1}, {"saajid", 2}, {"alex", 3}, {"john", 2}, {"mr", 0}}, "laura") == ("Get Out Now!"));
    assert(outed({{"tim", 1}, {"jim", 3}, {"randy", 9}, {"sandy", 6}, {"andy", 7}, {"katie", 6}, {"laura", 9}, {"saajid", 9}, {"alex", 9}, {"john", 9}, {"mr", 8}}, "katie") == ("Nice Work Champ!"));
    assert(outed({{"tim", 2}, {"jim", 4}, {"randy", 0}, {"sandy", 5}, {"andy", 8}, {"katie", 6}, {"laura", 2}, {"saajid", 2}, {"alex", 3}, {"john", 2}, {"mr", 8}}, "john") == ("Get Out Now!"));

    return 0;
}