#include <iostream>
#include <cassert>
#include <string>

class MaxRotate
{
public:
    static long long maxRot(long long n);
};

long long MaxRotate::maxRot(long long n)
{
    long long maxElement = n;
    std::string s = std::to_string(n);

    for (size_t i = 0; i < s.length() - 1; ++i)
    {
        char digit = s[i];
        s.erase(i, 1);
        s.push_back(digit);

        long long newNumber = std::stoll(s);

        maxElement = std::max(maxElement, newNumber);
    }

    return maxElement;
}

void dotest(long long n, long long expected)
{
    assert(MaxRotate::maxRot(n) == (expected));
}

int main()
{

    dotest(38458215, 85821534);
    dotest(195881031, 988103115);
    dotest(896219342, 962193428);
    dotest(69418307, 94183076);

    return 0;
}