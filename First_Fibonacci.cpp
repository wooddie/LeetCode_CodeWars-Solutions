#include <iostream>
#include <cassert>
#include <utility>

std::pair<int, int> solution(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b - a >= 0 && (b - a) <= a)
    {
        int prev = b - a;
        b = a;
        a = prev;
    }

    return {a, b};
}

int main()
{
    assert(solution(398, 644) == (std::pair<int, int>(2, 6)) && ("For solution(398, 644):\n"));
    assert(solution(15, 28) == (std::pair<int, int>(2, 13)) && ("For solution(15, 28):\n"));
    assert(solution(186, 301) == (std::pair<int, int>(3, 7)) && ("For solution(186, 301):\n"));
    assert(solution(265, 429) == (std::pair<int, int>(1, 12)) && ("For solution(265, 429):\n"));
    assert(solution(1186, 1919) == (std::pair<int, int>(2, 7)) && ("For solution(1186, 1919):\n"));

    return 0;
}