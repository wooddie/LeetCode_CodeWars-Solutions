#include <iostream>
#include <cassert>

bool solve(std::string st)
{
    int j = st.size() - 1;

    for (int i = 0; i < static_cast<int>(st.size()); ++i)
    {
        auto diff = std::abs(st[i] - st[j]);

        if (diff != 2 && diff != 0)
        {
            return false;
        }

        --j;
    }

    return true;
}

int main()
{
    assert(solve("abba") == (true));
    assert(solve("abaazaba") == (false));
    assert(solve("abccba") == (true));
    assert(solve("adfa") == (true));
    assert(solve("ae") == (false));
    assert(solve("sq") == (true));
    assert(solve("abzy") == (false));
    assert(solve("kxbkwgyydkcbtjcosgikfdyhuuprubpwthgflucpyylbofvqxkkvqthmdnywpaunfihvupbwpruwfybdmgeuocltdaidyyewmbzm") == (true));

    return 0;
}