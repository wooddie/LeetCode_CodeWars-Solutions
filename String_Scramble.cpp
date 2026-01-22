#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

std::string scramble(
    const std::string &str,
    const std::vector<std::size_t> &indices)
{
    std::string newStr;
    newStr.resize(str.size());

    for (size_t i = 0; i < indices.size(); ++i)
    {
        newStr[indices[i]] = str[i];
    }

    return newStr;
}

void doTest(
    const std::string &str,
    const std::vector<std::size_t> &indices,
    const std::string &expected)
{
    assert(
        scramble(str, indices) == (expected) && "Fail!");
}

int main()
{
    doTest(
        "abcd",
        {0, 3, 1, 2},
        "acdb");

    doTest(
        "sc301s",
        {4, 0, 3, 1, 5, 2},
        "c0s3s1");

    doTest(
        "bskl5",
        {2, 1, 4, 3, 0},
        "5sblk");

    return 0;
}