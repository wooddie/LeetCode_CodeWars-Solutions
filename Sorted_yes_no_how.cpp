#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::string is_sorted_and_how(const std::vector<int> &numbers)
{

    if (std::is_sorted(numbers.begin(), numbers.end()))
    {
        return "yes, ascending";
    }

    if (std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>()))
    {
        return "yes, descending";
    }

    return "no";
}

std::string vector_to_string(const std::vector<int> &vec)
{
    std::ostringstream oss;
    oss << "{ ";
    for (size_t i = 0; i < vec.size(); ++i)
        oss << vec[i] << ((i == vec.size() - 1) ? "" : ", ");
    oss << " }";
    return oss.str();
}

void do_test(const std::vector<int> &input, const std::string &expected)
{
    std::string message = "input = " + vector_to_string(input) + "\n";
    std::string actual = is_sorted_and_how(input);
    assert(actual == (expected));
}

int main()
{
    do_test({1, 1, 2, 3}, "yes, ascending");
    do_test({9, 9, -5, -7}, "yes, descending");
    do_test({-6, -6, 5, -9}, "no");
    do_test({1, 3, 9, 4}, "no");
    do_test({50, 40, 30, 10, 20}, "no");

    do_test({1, 2}, "yes, ascending");
    do_test({2, 1}, "yes, descending");

    do_test({-6, -5, -9}, "no");
    do_test({1, 2, 2}, "yes, ascending");
    do_test({+20, 0, 0, -20}, "yes, descending");

    std::cout << "all tests passed!" << std::endl;

    return 0;
}