#include <iostream>
#include <cassert>
#include <vector>

char findMissingLetter(const std::vector<char> &chars)
{
    for (size_t i = 1; i < chars.size(); ++i)
    {
        if (chars[i] - chars[i - 1] != 1)
        {
            return chars[i] - 1;
        }
    }

    return chars[0] - 1;
}

int main()
{
    assert(findMissingLetter({'a', 'b', 'c', 'd', 'f'}) == ('e') && ("Incorrect output for input = ['a', 'b', 'c', 'd', 'f']"));
    assert(findMissingLetter({'O', 'Q', 'R', 'S'}) == ('P') && ("Incorrect output for input = ['O', 'Q', 'R', 'S']"));

    return 0;
}