#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::string smash(const std::vector<std::string> &words)
{
    if (words.empty())
        return "";

    std::string res;

    for (const auto &w : words)
    {
        res += w + " ";
    }

    res.pop_back();

    return res;
}

int main()
{
    //(empty_array_should_return_empty_string)
    assert(smash({}) == (""));

    //(one_word_array_should_return_word)
    assert(smash({"hello"}) == ("hello"));

    //(multiple_words_should_be_space_separated)
    assert(smash({"hello", "world"}) == ("hello world"));
    assert(smash({"hello", "amazing", "world"}) == ("hello amazing world"));
    assert(smash({"this", "is", "a", "really", "long", "sentence"}) == ("this is a really long sentence"));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}