#include <iostream>
#include <cassert>
#include <string>

std::string get_middle(std::string input)
{
    int idx = input.size() / 2;

    if (input.size() % 2 != 0)
    {
        return std::string(1, input[idx]);
    }

    std::string res = input.substr(idx - 1, 2);

    return res;
}

int main()
{
    assert(get_middle("test") == ("es"));
    assert(get_middle("testing") == ("t"));
    assert(get_middle("middle") == "dd");
    assert(get_middle("A") == "A");

    return 0;
}