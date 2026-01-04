#include <string>
#include <cassert>
#include <iostream>

int getCount(const std::string &inputStr)
{
    int num_vowels = 0;

    for (const auto &c : inputStr)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            num_vowels++;
        }
    }

    return num_vowels;
}

int main()
{
    assert(getCount("abracadabra") == (5));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}