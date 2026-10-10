#include <iostream>
#include <cassert>
#include <string>
#include <unordered_set>

bool is_isogram(const std::string &str)
{
    std::string copy_str = str;
    if (str.empty())
    {
        return true;
    }

    std::unordered_set<char> list;

    std::transform(copy_str.begin(), copy_str.end(), copy_str.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    for (const auto c : copy_str)
    {
        if (!list.insert(c).second)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    assert(is_isogram("") == (true) && (R"(Incorrect result for input = "" (the empty string is a valid isogram):)"));

    assert(is_isogram("a") == (true) && (R"(Incorrect result for input = "a":)"));
    assert(is_isogram("X") == (true) && (R"(Incorrect result for input = "X":)"));

    assert(is_isogram("ab") == (true) && (R"(Incorrect result for input = "ab":)"));
    assert(is_isogram("Ba") == (true) && (R"(Incorrect result for input = "Ba":)"));
    assert(is_isogram("acb") == (true) && (R"(Incorrect result for input = "acb":)"));
    assert(is_isogram("GROWTH") == (true) && (R"(Incorrect result for input = "GROWTH":)"));
    assert(is_isogram("isogram") == (true) && (R"(Incorrect result for input = "isogram":)"));
    assert(is_isogram("Dermatoglyphics") == (true) && (R"(Incorrect result for input = "Dermatoglyphics":)"));
    assert(is_isogram("thumbscrewjapingly") == (true) && (R"(Incorrect result for input = "thumbscrewjapingly":)"));
    assert(is_isogram("acdefghijklmnopqrstuvwxBz") == (true) && (R"(Incorrect result for input = "acdefghijklmnopqrstuvwxBz":)"));
    assert(is_isogram("abcdefghijklmnopqrstuvwxyz") == (true) && (R"(Incorrect result for input = "abcdefghijklmnopqrstuvwxyz":)"));
    assert(is_isogram("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == (true) && (R"(Incorrect result for input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ":)"));

    assert(is_isogram("aa") == (false) && (R"(Incorrect result for input = "aa":)"));
    assert(is_isogram("aA") == (false) && (R"(Incorrect result for input = "aA":)"));
    assert(is_isogram("aba") == (false) && (R"(Incorrect result for input = "aba":)"));
    assert(is_isogram("ZzZ") == (false) && (R"(Incorrect result for input = "ZzZ":)"));
    assert(is_isogram("moose") == (false) && (R"(Incorrect result for input = "moose":)"));
    assert(is_isogram("moOse") == (false) && (R"(Incorrect result for input = "moOse":)"));
    assert(is_isogram("uNIQUe") == (false) && (R"(Incorrect result for input = "uNIQUe":)"));
    assert(is_isogram("roboto") == (false) && (R"(Incorrect result for input = "roboto":)"));
    assert(is_isogram("parmesan") == (false) && (R"(Incorrect result for input = "parmesan":)"));
    assert(is_isogram("LIPGLOSS") == (false) && (R"(Incorrect result for input = "LIPGLOSS":)"));
    assert(is_isogram("isIsogram") == (false) && (R"(Incorrect result for input = "isIsogram":)"));
    assert(is_isogram("abcdefghijklmnopqrstuwwxyz") == (false) && (R"(Incorrect result for input = "abcdefghijklmnopqrstuwwxyz":)"));
    assert(is_isogram("abcdefghijklmnopqrstuvwxyzA") == (false) && (R"(Incorrect result for input = "abcdefghijklmnopqrstuvwxyzA":)"));
    assert(is_isogram("ABCDEFGHIJKLMNOPQRSTUVWXYZh") == (false) && (R"(Incorrect result for input = "ABCDEFGHIJKLMNOPQRSTUVWXYZh":)"));

    return 0;
}