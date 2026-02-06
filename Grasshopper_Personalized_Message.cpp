#include <iostream>
#include <cassert>
#include <string>

std::string greet(const std::string &name, const std::string &owner)
{
    return (name == owner) ? "Hello boss" : "Hello guest";
}

int main()
{
    assert(greet("Daniel", "Daniel") == ("Hello boss"));
    assert(greet("Greg", "Daniel") == ("Hello guest"));

    return 0;
}