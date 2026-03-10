#include <iostream>
#include <cassert>
#include <vector>
#include <string>

bool check(const std::vector<std::string> &seq, const std::string &elem)
{
    if (std::find(seq.begin(), seq.end(), elem) != seq.end())
    {
        return true;
    }

    return false;
}

int main()
{
    assert(check({}, "a") == (false));
    assert(check({"a", "b", "c"}, "b") == (true));
    assert(check({"a", "b", "c"}, "e") == (false));

    return 0;
}