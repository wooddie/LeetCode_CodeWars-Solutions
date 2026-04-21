#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>

class Opstrings
{
public:
    static std::string vertMirror(const std::string &strng);
    static std::string horMirror(const std::string &strng);
    static std::string oper(std::string (*func)(const std::string &s), const std::string &s);
};

std::string Opstrings::vertMirror(const std::string &strng)
{
    std::stringstream ss(strng);
    std::string segment;
    std::string result;

    while (std::getline(ss, segment, '\n'))
    {
        if (segment.empty())
            continue;

        result += std::string(segment.rbegin(), segment.rend()) + "\n";
    }

    if (!result.empty())
    {
        result.pop_back();
    }

    return result;
}

std::string Opstrings::horMirror(const std::string &strng)
{
    std::stringstream ss(strng);
    std::string segment;
    std::string result;

    while (std::getline(ss, segment, '\n'))
    {
        if (segment.empty())
            continue;

        result.insert(0, segment + "\n");
    }

    if (!result.empty())
    {
        result.pop_back();
    }

    return result;
}

std::string Opstrings::oper(std::string (*func)(const std::string &s), const std::string &s)
{
    return func(s);
}

void testequal(std::string ans, std::string sol)
{
    assert(ans == (sol));
}

template <typename Func>
static void dotest(Func func, std::string s, std::string expected)
{
    testequal(Opstrings::oper(func, s), expected);
}

int main()
{
    // vertMirror_Tests

    std::string s = "hSgdHQ\nHnDMao\nClNNxX\niRvxxH\nbqTVvA\nwvSyRu";
    std::string sol = "QHdgSh\noaMDnH\nXxNNlC\nHxxvRi\nAvVTqb\nuRySvw";
    dotest(Opstrings::vertMirror, s, sol);

    // horMirror_Tests

    s = "lVHt\nJVhv\nCSbg\nyeCt";
    sol = "yeCt\nCSbg\nJVhv\nlVHt";
    dotest(Opstrings::horMirror, s, sol);

    return 0;
}