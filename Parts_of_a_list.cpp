#include <iostream>
#include <cassert>
#include <string>
#include <vector>

class PartList
{
public:
    static std::vector<std::pair<std::string, std::string>> partlist(std::vector<std::string> &arr);
};

std::vector<std::pair<std::string, std::string>> PartList::partlist(std::vector<std::string> &arr)
{
    std::vector<std::pair<std::string, std::string>> result;
    std::pair<std::string, std::string> str;

    str.first = arr[0];

    for (int i = 1; i < arr.size(); ++i)
    {
        str.second += arr[i];
        if (i != arr.size() - 1)
        {
            str.second += " ";
        }
    }

    result.push_back(str);

    while (!str.second.empty())
    {
        size_t spacePos = str.second.find(' ');

        if (spacePos != std::string::npos)
        {
            str.first += " " + str.second.substr(0, spacePos);
            str.second.erase(0, spacePos + 1);

            result.push_back(str);
        }
        else
        {
            break;
        }
    }

    return result;
}

void testequal(std::vector<std::pair<std::string, std::string>> ans, std::vector<std::pair<std::string, std::string>> sol)
{
    assert(ans == (sol));
}

int main()
{
    std::vector<std::string> s = {"cdIw", "tzIy", "xDu", "rThG"};
    std::vector<std::pair<std::string, std::string>> sol = {{"cdIw", "tzIy xDu rThG"}, {"cdIw tzIy", "xDu rThG"}, {"cdIw tzIy xDu", "rThG"}};
    std::vector<std::pair<std::string, std::string>> ans = PartList::partlist(s);
    testequal(ans, sol);

    s = {"I", "wish", "I", "hadn't", "come"};
    sol = {{"I", "wish I hadn't come"}, {"I wish", "I hadn't come"}, {"I wish I", "hadn't come"}, {"I wish I hadn't", "come"}};
    ans = PartList::partlist(s);
    testequal(ans, sol);

    s = {"vJQ", "anj", "mQDq", "sOZ"};
    sol = {{"vJQ", "anj mQDq sOZ"}, {"vJQ anj", "mQDq sOZ"}, {"vJQ anj mQDq", "sOZ"}};
    ans = PartList::partlist(s);
    testequal(ans, sol);

    return 0;
}