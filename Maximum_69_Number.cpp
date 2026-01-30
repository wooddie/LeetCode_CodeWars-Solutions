//
// Created by Канапия on 30.01.2026.
//

#include <iostream>
#include <string>

class Solution {
public:
    static int maximum69Number(int num) {
        int maxNum = num;
        std::string s = std::to_string(num);

        for (int i = 0; i < s.size(); ++i) {
            std::string cur = s;

            if (cur[i] == '9') {
                cur[i] = '6';
            } else {
                cur[i] = '9';
            }

            maxNum = std::max(maxNum, std::stoi(cur));
        }

        return maxNum;
    }
};

int main() {
    std::cout << Solution::maximum69Number(9669) << std::endl;
    std::cout << Solution::maximum69Number(9996) << std::endl;
    std::cout << Solution::maximum69Number(9999) << std::endl;

    return 0;
}
