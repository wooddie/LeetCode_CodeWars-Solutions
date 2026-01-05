#include <iostream>
#include <cassert>
#include <string>

std::string group_by_commas(int n)
{
    if (n < 1000)
    {
        return std::to_string(n);
    }

    std::string num = std::to_string(n);

    for (int i = (int)num.size() - 3; i > 0; i -= 3)
    {
        num.insert(i, ",");
    }

    return num;
}

int main()
{
    assert(group_by_commas(1) == ("1"));
    assert(group_by_commas(12) == ("12"));
    assert(group_by_commas(123) == ("123"));
    assert(group_by_commas(12345) == ("12,345"));
    assert(group_by_commas(123456) == ("123,456"));
    assert(group_by_commas(1234567) == ("1,234,567"));
    assert(group_by_commas(12345678) == ("12,345,678"));
    assert(group_by_commas(123456789) == ("123,456,789"));
    assert(group_by_commas(1234567890) == ("1,234,567,890"));
    assert(group_by_commas(1234) == ("1,234"));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}