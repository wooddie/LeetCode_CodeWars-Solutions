#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

std::string flyBy(std::string lamp, std::string drone)
{
    std::fill(lamp.begin(), lamp.begin() + drone.size(), 'o');

    return lamp;
}

int main()
{
    assert(flyBy("xxxxxx", "====T") == ("ooooox"));
    assert(flyBy("xxxxxxxxx", "==T") == ("oooxxxxxx"));
    assert(flyBy("xxxxxxxxxxxxxxx", "=========T") == ("ooooooooooxxxxx"));

    return 0;
}