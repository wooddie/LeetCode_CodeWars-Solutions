#include <iostream>
#include <cassert>

class Thirteen
{
public:
    static long long thirt(long long n);
};

long long Thirteen::thirt(long long n)
{
    int remainders[] = {1, 10, 9, 12, 3, 4};

    while (true)
    {
        long long cur = 0;
        long long temp = n;
        int i = 0;

        while (temp > 0)
        {
            cur += (temp % 10) * remainders[i % 6];
            temp /= 10;
            i++;
        }

        if (cur == n)
        {
            return cur;
        }

        n = cur;
    }
}

void testing(long long ans, long long sol)
{
    assert(ans == (sol));
}

int main()
{
    testing(Thirteen::thirt(8529), 79);
    testing(Thirteen::thirt(85299258), 31);
    testing(Thirteen::thirt(5634), 57);
    testing(Thirteen::thirt(1111111111), 71);
    testing(Thirteen::thirt(987654321), 30);

    return 0;
}