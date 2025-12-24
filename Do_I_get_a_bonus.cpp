#include <iostream>
#include <string>
#include <cassert>

std::string bonus_time(int salary, bool bonus)
{
    return (bonus) ? "$" + std::to_string(salary * 10) : "$" + std::to_string(salary);
}

int main()
{
    assert(bonus_time(10000, true) == ("$100000"));
    assert(bonus_time(25000, true) == ("$250000"));
    assert(bonus_time(10000, false) == ("$10000"));
    assert(bonus_time(60000, false) == ("$60000"));
    assert(bonus_time(2, true) == ("$20"));
    assert(bonus_time(78, false) == ("$78"));
    assert(bonus_time(67890, true) == ("$678900"));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}