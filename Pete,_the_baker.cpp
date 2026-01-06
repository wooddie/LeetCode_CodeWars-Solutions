#include <unordered_map>
#include <vector>
#include <cassert>
#include <iostream>
#include <climits>

using Ingredients = std::unordered_map<std::string, int>;
int cakes(const Ingredients &recipe, const Ingredients &available);

int cakes(const Ingredients &recipe, const Ingredients &available)
{
    int result = INT_MAX;

    for (const auto &item : recipe)
    {
        auto it = available.find(item.first);
        if (it == available.end())
            return 0;

        int possible = it->second / item.second;
        result = std::min(result, possible);
    }

    return result;
}

int main()
{
    Ingredients recipe = {{"flour", 500}, {"sugar", 200}, {"eggs", 1}},
                available = {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}};
    assert(cakes(recipe, available) == (2));

    recipe = {{"apples", 3}, {"flour", 300}, {"milk", 100}, {"sugar", 150}, {"oil", 100}},
    available = {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}};
    assert(cakes(recipe, available) == (0));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}