//
// Created by Канапия on 31.01.2026.
//

#include <iostream>
#include <vector>

class Solution {
public:
    static char nextGreatestLetter(const std::vector<char> &letters, char target) {
        int left = 0, right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return letters[left % letters.size()];
    }
};

int main() {
    std::vector<char> l = {'c', 'f', 'j'};
    std::cout << Solution::nextGreatestLetter(l, 'a') << std::endl;
    std::cout << Solution::nextGreatestLetter(l, 'c') << std::endl;
    l = {'x', 'x', 'y', 'y'};
    std::cout << Solution::nextGreatestLetter(l, 'z') << std::endl;

    return 0;
}
