//
// Created by Канапия on 29.01.2026.
//

#include <iostream>

class Solution {
public:
    static int subtractProductAndSum(int n) {
        int addition = 0;
        int multiplication = 1;

        while (n > 0) {
            int digit = n % 10;
            addition += digit;
            multiplication *= digit;
            n /= 10;
        }

        return multiplication - addition;
    }
};

int main() {
    std::cout << Solution::subtractProductAndSum(234) << std::endl;

    std::cout << Solution::subtractProductAndSum(4421) << std::endl;

    return 0;
}
