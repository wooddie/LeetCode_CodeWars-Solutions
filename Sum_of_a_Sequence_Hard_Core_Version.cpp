#include <iostream>
#include <cassert>

long long int sequence_sum(long long int begin_number, long long int end_number, long long step)
{
    if (step > 0 && begin_number > end_number) return 0;
    
    if (step < 0 && begin_number < end_number) return 0;

    long long int n = (end_number - begin_number) / step + 1;

    if (n <= 0) return 0;

    long long int aLast = begin_number + (n - 1) * step;
    
    return (n * (begin_number + aLast)) / 2;
}

int main()
{
    assert(sequence_sum(2, 6, 2) == (12));

    assert(sequence_sum(1, 5, 1) == (15));

    assert(sequence_sum(1, 5, 3) == (5));

    assert(sequence_sum(-1, -5, -3) == (-5));

    assert(sequence_sum(16, 15, 3) == (0));

    assert(sequence_sum(780, 6851543, 5) == (4694363402480));

    assert(sequence_sum(9383, 71418, 2) == (1253127200));

    assert(sequence_sum(20, 673388797, 5) == (45345247259849570));

    return 0;
}