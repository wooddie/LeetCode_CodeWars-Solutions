//
// Created by Канапия on 02.02.2026.
//

#include <iostream>

class Solution {
public:
    static int numberOfMatches(int n) {
        int matches = 0;
        int advance = n;

        while (advance != 1) {
            if (advance % 2 == 0) {
                matches += advance / 2;
                advance /= 2;
            } else {
                matches += (advance - 1) / 2;
                advance = (advance - 1) / 2 + 1;
            }
        }

        return matches;
    }
};

int main() {
    std::cout << Solution::numberOfMatches(7) << std::endl;
    std::cout << Solution::numberOfMatches(14) << std::endl;

    return 0;
}
