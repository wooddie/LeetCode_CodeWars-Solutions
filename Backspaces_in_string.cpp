#include <iostream>
#include <string>
#include <cassert>

std::string cleanString(const std::string &s)
{
    std::string sCopy = s;
    int count = 0;

    for (int i = sCopy.size() - 1; i >= 0; --i)
    {
        if (sCopy[i] == '#')
        {
            sCopy.erase(i, 1);
            ++count;
        }
        else if (count > 0)
        {
            sCopy.erase(i, 1);
            --count;
        }
    }

    return sCopy;
}

int main()
{
    assert(cleanString("abc#d##c") == ("ac"));
    assert(cleanString("abc####d##c#") == (""));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}