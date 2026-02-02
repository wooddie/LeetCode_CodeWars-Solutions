//
// Created by Канапия on 02.02.2026.
//

#include <iostream>

class Solution {
public:
    static bool divisorGame(int n) {
        return (n % 2 == 0) ? true : false;
    }
};

int main() {
    std::cout << std::boolalpha << Solution::divisorGame(2) << std::endl;

    std::cout << std::boolalpha << Solution::divisorGame(3) << std::endl;

    return 0;
}
