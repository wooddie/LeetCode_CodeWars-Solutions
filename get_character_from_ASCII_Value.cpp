#include <iostream>
#include <cassert>

char get_char(int i)
{
    return static_cast<char>(i);
}

int main()
{
    assert(get_char(55) == ('7'));
    assert(get_char(56) == ('8'));
    assert(get_char(57) == ('9'));
    assert(get_char(58) == (':'));
    assert(get_char(59) == (';'));
    assert(get_char(60) == ('<'));
    assert(get_char(61) == ('='));
    assert(get_char(62) == ('>'));
    assert(get_char(63) == ('?'));
    assert(get_char(64) == ('@'));
    assert(get_char(65) == ('A'));

    return 0;
}