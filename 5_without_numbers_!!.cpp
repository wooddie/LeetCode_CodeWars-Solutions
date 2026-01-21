#include <iostream>
#include <cassert>

int unusual_five()
{
    std::string s = "aaaaa";
    
    return s.size();
}

int main()
{
    assert(unusual_five() == (5) && ("Incorrect output for unusual_five():"));

    return 0;
}