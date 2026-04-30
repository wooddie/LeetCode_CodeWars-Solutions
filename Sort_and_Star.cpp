#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

std::string twoSort(std::vector<std::string> s)
{
    std::sort(s.begin(), s.end());
    std::string min = s[0];

    for (size_t i = 0; i < min.size() - 1; ++i)
    {
        min.insert(i + 1, "***");
        i += 3;
    }

    return min;
}

int main()
{
    // ExampleTest1
    std::string expected = "b***i***t***c***o***i***n";
    std::string actual = twoSort(std::vector<std::string>{"bitcoin", "take", "over", "the", "world", "maybe", "who", "knows", "perhaps"});
    std::cout << actual << std::endl;
    assert(actual == (expected));

    // ExampleTest2
    expected = "a***r***e";
    actual = twoSort(std::vector<std::string>{"turns", "out", "random", "test", "cases", "are", "easier", "than", "writing", "out", "basic", "ones"});
    std::cout << actual << std::endl;
    assert(actual == (expected));

    return 0;
}