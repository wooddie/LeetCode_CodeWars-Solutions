#include <iostream>
#include <cassert>
#include <string>
#include <vector>

//          ／＞　　フ
//　　　　　| 　n　n 彡
//　 　　　／`ミ＿xノ
//　　 　 /　　　 　 |
//　　　 /　 ヽ　　 ﾉ
//　 　 │　　|　|　|
//　／￣|　　 |　|　|
//　| (￣ヽ＿_ヽ_)__)
//　＼二つ
// thx Cougar208 for this car!

std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> res;
    std::string cur;

    for (size_t i = 0; i < s.size(); ++i)
    {
        cur += s[i];

        if (cur.size() == 2)
        {
            res.push_back(cur);
            cur.clear();
        }
    }

    if (!cur.empty())
    {
        cur += '_';
        res.push_back(cur);
    }

    return res;
}

void do_test(std::string input, std::vector<std::string> expected)
{
    assert(solution(input) == expected);
}

int main()
{

    //(even_length)

    do_test("abcdef", {"ab", "cd", "ef"});
    do_test("HelloWorld", {"He", "ll", "oW", "or", "ld"});

    //(odd_length)

    do_test("abcde", {"ab", "cd", "e_"});
    do_test("LovePizza", {"Lo", "ve", "Pi", "zz", "a_"});

    return 0;
}