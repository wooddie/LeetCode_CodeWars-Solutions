#include <iostream>
#include <cassert>
#include <string>

int wordsToMarks(const std::string &str)
{
    int sum = 0;

    for (size_t i = 0; i < str.size(); ++i)
    {
        sum += str[i] - 96;
    }

    return sum;
}

int main()
{
    assert(wordsToMarks("friends") == (75));
    assert(wordsToMarks("family") == (66));
    assert(wordsToMarks("selfness") == (99));
    assert(wordsToMarks("knowledge") == (96));

    return 0;
}