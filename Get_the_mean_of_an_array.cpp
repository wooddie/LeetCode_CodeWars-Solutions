#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

int get_average(std::vector<int> marks)
{
    int sum = std::accumulate(marks.begin(), marks.end(), 0);

    return sum / marks.size();
}

int main()
{
    assert(get_average(std::vector<int>{2, 2, 2, 2}) == (2));
    assert(get_average(std::vector<int>{1, 5, 87, 45, 8, 8}) == (25));
    assert(get_average(std::vector<int>{2, 5, 13, 20, 16, 16, 10}) == (11));
    assert(get_average(std::vector<int>{1, 2, 15, 15, 17, 11, 12, 17, 17, 14, 13, 15, 6, 11, 8, 7}) == (11));

    return 0;
}