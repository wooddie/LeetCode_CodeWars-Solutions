#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <utility>

std::vector<std::string> openOrSenior(std::vector<std::pair<int, int>> &data)
{
    std::vector<std::string> result;

    for (size_t i = 0; i < data.size(); ++i)
    {
        result.push_back((data[i].first >= 55 && data[i].second >= 7) ? "Senior" : "Open");
    }

    return result;
}

int main()
{
    std::vector<std::string> openOrSenior(std::vector<std::pair<int, int>> & data);

    std::vector<std::pair<int, int>> data = {{45, 12}, {55, 21}, {19, -2}, {104, 20}};
    std::vector<std::string> output = {"Open", "Senior", "Open", "Senior"};
    assert(openOrSenior(data) == (output));

    data = {{16, 23}, {73, 1}, {56, 20}, {1, -1}};
    output = {"Open", "Open", "Senior", "Open"};
    assert(openOrSenior(data) == (output));

    return 0;
}