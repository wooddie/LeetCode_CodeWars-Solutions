#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>

std::string dtos(double x)
{
    std::ostringstream oss;
    oss << std::setprecision(17) << x;
    return oss.str();
}

void do_test(double x)
{
    assert(std::stod(dtos(x)) == (x) && ("std::stod(dtos(x)) != x"));
}

int main()
{
    do_test(123.456);
    do_test(-123.456);
    do_test(0.0);
    do_test(3.14159265358979323846264338327950288);
    do_test(std::numeric_limits<double>::max());
    do_test(std::numeric_limits<double>::min());

    return 0;
}