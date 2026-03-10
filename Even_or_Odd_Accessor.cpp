#include <iostream>
#include <cassert>
#include <string>

struct EvenOrOdd
{
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    std::string operator()(T number) const
    {
        return check(number);
    }

    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    std::string operator[](T number) const
    {
        return check(number);
    }

private:
    template <typename T>
    std::string check(T n) const
    {
        return n % 2 == 0 ? "Even" : "Odd";
    }
};

inline constexpr EvenOrOdd evenOrOdd;

int main()
{
    // zero
    assert(evenOrOdd(0) == ("Even") && ("Incorrect answer for number=(0)"));
    assert(evenOrOdd[0] == ("Even") && ("Incorrect answer for number=[0]"));

    // positive_odd_numbers
    assert(evenOrOdd(1) == ("Odd") && ("Incorrect answer for number=(1)"));
    assert(evenOrOdd[21] == ("Odd") && ("Incorrect answer for number=[21]"));
    assert(evenOrOdd[1] == ("Odd") && ("Incorrect answer for number=[1]"));
    assert(evenOrOdd(21) == ("Odd") && ("Incorrect answer for number=(21)"));

    // positive_even_numbers
    assert(evenOrOdd[2] == ("Even") && ("Incorrect answer for number=[2]"));
    assert(evenOrOdd[100] == ("Even") && ("Incorrect answer for number=[100]"));
    assert(evenOrOdd(2) == ("Even") && ("Incorrect answer for number=(2)"));
    assert(evenOrOdd(100) == ("Even") && ("Incorrect answer for number=(100)"));

    // negative_odd_numbers
    assert(evenOrOdd[-1] == ("Odd") && ("Incorrect answer for number=[-1]"));
    assert(evenOrOdd(-21) == ("Odd") && ("Incorrect answer for number=(-21)"));
    assert(evenOrOdd(-1) == ("Odd") && ("Incorrect answer for number=(-1)"));
    assert(evenOrOdd[-21] == ("Odd") && ("Incorrect answer for number=[-21]"));

    // negative_even_numbers
    assert(evenOrOdd[-2] == ("Even") && ("Incorrect answer for number=[-2]"));
    assert(evenOrOdd[-100] == ("Even") && ("Incorrect answer for number=[-100]"));
    assert(evenOrOdd(-2) == ("Even") && ("Incorrect answer for number=(-2)"));
    assert(evenOrOdd(-100) == ("Even") && ("Incorrect answer for number=(-100)"));

    return 0;
}