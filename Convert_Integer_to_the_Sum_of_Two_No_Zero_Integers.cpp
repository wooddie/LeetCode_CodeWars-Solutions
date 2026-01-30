//
// Created by Канапия on 30.01.2026.
//

#include <iostream>
#include <vector>

class Solution {
public:
    static bool nonZero(int num) {
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) { return false; }
            num = num / 10;
        }

        return true;
    }

    static std::vector<int> getNoZeroIntegers(int n) {
        std::vector<int> res;

        int a = 1;

        while (true) {
            int b = n - a;

            bool aBool = nonZero(a);
            bool bBool = nonZero(b);

            if (aBool && bBool) {
                res.push_back(a);
                res.push_back(b);
                break;
            } else {
                a++;
            }
        }

        return res;
    }
};

int main() {
    for (const auto &n: Solution::getNoZeroIntegers(2)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (const auto &n: Solution::getNoZeroIntegers(11)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
