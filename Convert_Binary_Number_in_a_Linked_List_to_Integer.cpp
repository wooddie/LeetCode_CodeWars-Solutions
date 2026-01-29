//
// Created by Канапия on 29.01.2026.
//

#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    static int getDecimalValue(ListNode *head) {
        std::string res;

        ListNode *cur = head;
        while (cur) {
            res += std::to_string(cur->val);
            cur = cur->next;
        }

        return std::stoi(res, nullptr, 2);
    }
};

ListNode *buildList(const std::vector<int> &v) {
    if (v.empty()) return nullptr;

    ListNode *head = new ListNode(v[0]);
    ListNode *cur = head;

    for (int i = 1; i < v.size(); ++i) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    return head;
}

int main() {
    ListNode *list1 = buildList({1, 0, 1});
    std::cout << Solution::getDecimalValue(list1) << std::endl;

    ListNode *list2 = buildList({0});
    std::cout << Solution::getDecimalValue(list2) << std::endl;

    return 0;
}
