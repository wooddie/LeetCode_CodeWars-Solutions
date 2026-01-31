//
// Created by Канапия on 30.01.2026.
//

#include <iostream>

class Solution {
public:
    static double angleClock(int hour, int minutes) {
        double res = std::abs((30 * hour) - (5.5 * minutes));

        return (res < 180) ? res : 360 - res;
    }
};

int main(int argc, char const *argv[]) {
    std::cout << Solution::angleClock(12, 30) << std::endl;
    std::cout << Solution::angleClock(3, 30) << std::endl;
    std::cout << Solution::angleClock(3, 15) << std::endl;

    return 0;
}