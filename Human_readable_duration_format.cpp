#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

std::string format_duration(int seconds)
{
    if (seconds == 0)
        return "now";

    std::vector<std::pair<std::string, int>> units = {
        {"year", 31536000},
        {"day", 86400},
        {"hour", 3600},
        {"minute", 60},
        {"second", 1}};

    std::vector<std::string> parts;

    for (auto &[name, value] : units)
    {
        int count = seconds / value;
        seconds %= value;

        if (count > 0)
        {
            std::string part = std::to_string(count) + " " + name;
            if (count > 1)
                part += "s";
            parts.push_back(part);
        }
    }

    std::string res;
    for (size_t i = 0; i < parts.size(); ++i)
    {
        if (i > 0)
        {
            if (i == parts.size() - 1)
                res += " and ";
            else
                res += ", ";
        }
        res += parts[i];
    }

    return res;
}

int main()
{
    assert(format_duration(0) == ("now"));
    assert(format_duration(1) == ("1 second"));
    assert(format_duration(62) == ("1 minute and 2 seconds"));
    assert(format_duration(120) == ("2 minutes"));
    assert(format_duration(3662) == ("1 hour, 1 minute and 2 seconds"));

    return 0;
}