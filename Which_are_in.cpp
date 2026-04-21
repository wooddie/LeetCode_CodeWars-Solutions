#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>

class WhichAreIn
{
public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);
};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
    std::set<std::string> sortSet;

    for (const auto &a1 : array1)
    {
        for (const auto &a2 : array2)
        {
            if (a2.find(a1) != std::string::npos)
            {
                sortSet.insert(a1);

                break;
            }
        }
    }

    return std::vector<std::string>(sortSet.begin(), sortSet.end());
}

void testequal(std::vector<std::string> &ans, std::vector<std::string> &sol)
{
    assert(ans == (sol));
}

int main()
{
    std::vector<std::string> arr1 = {"arp", "live", "strong"};
    std::vector<std::string> arr2 = {"lively", "alive", "harp", "sharp", "armstrong"};
    std::vector<std::string> sol1 = {"arp", "live", "strong"};
    std::vector<std::string> ans1 = WhichAreIn::inArray(arr1, arr2);
    testequal(ans1, sol1);

    std::cout << "TEST PASSED!" << std::endl;

    return 0;
}