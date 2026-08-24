#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

std::string TwoToOne::longest(const std::string &s1, const std::string &s2)
{
    std::string result = s1 + s2;

    std::sort(result.begin(), result.end());

    result.erase(std::unique(result.begin(), result.end()), result.end());

    return result;
}

void testequal(std::string ans, std::string sol)
{
    assert(ans == (sol));
}
void dotest(std::string a1, std::string a2, std::string expected)
{
    testequal(TwoToOne::longest(a1, a2), expected);
}

int main()
{

    dotest("aretheyhere", "yestheyarehere", "aehrsty");
    dotest("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");

    return 0;
}