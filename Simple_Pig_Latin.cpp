#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <sstream>

std::string pig_it(std::string str)
{
    std::string res;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word)
    {
        if (std::isalpha(word[0]))
        {
            std::rotate(word.begin(), word.begin() + 1, word.end());
            res += word + "ay ";
        }
        else
        {
            res += word + " ";
        }
    }

    res.pop_back();

    return res;
}

int main()
{
    assert(pig_it("This is my string") == ("hisTay siay ymay tringsay"));
    assert(pig_it("Pig latin is cool") == ("igPay atinlay siay oolcay"));
    assert(pig_it("Acta est fabula") == ("ctaAay steay abulafay"));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}