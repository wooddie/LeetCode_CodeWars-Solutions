//
// Created by Канапия on 29.01.2026.
//

#include <iostream>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> res(num_people, 0);
        int candies_to_give = 1;
        int i = 0;

        while (candies > 0) {
            int person_idx = i % num_people;

            int current_portion = std::min(candies, candies_to_give);

            res[person_idx] += current_portion;

            candies -= current_portion;
            candies_to_give++;
            i++;
        }

        return res;
    }
};

int main() {
    Solution s1;

    for (const auto &n: s1.distributeCandies(7, 4)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    for (const auto &n: s1.distributeCandies(10, 3)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
