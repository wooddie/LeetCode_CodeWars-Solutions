#include <iostream>
#include <cassert>

class Movie
{
public:
    static int movie(int card, int ticket, double perc);
};

int Movie::movie(int card, int ticket, double perc)
{
    int systemA = 0;
    double systemB = card;
    int times = 0;
    double currentTicketPrice = ticket * perc;

    while (systemA < systemB)
    {
        times++;
        systemA = ticket * times;

        systemB += currentTicketPrice;
        currentTicketPrice *= perc;
    }

    return times;
}

void testequal(int ans, int sol)
{
    assert(ans == (sol));
}

int main()
{
    testequal(Movie::movie(500, 15, 0.9), 43);
    testequal(Movie::movie(100, 10, 0.95), 24);

    return 0;
}