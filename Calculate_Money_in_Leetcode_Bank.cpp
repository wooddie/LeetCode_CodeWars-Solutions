//
// Created by Канапия on 02.02.2026.
//

#include  <iostream>

class Solution {
public:
    static int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        return (7 * weeks * (weeks + 7) / 2) + (days * (2 * weeks + days + 1) / 2);
    }
};

int main() {
    std::cout << Solution::totalMoney(4) << std::endl;
    std::cout << Solution::totalMoney(10) << std::endl;
    std::cout << Solution::totalMoney(20) << std::endl;

    return 0;
}
