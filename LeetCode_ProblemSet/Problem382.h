//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM382_H
#define PROBLEM382_H
#include <cstdlib>
#include <vector>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    std::vector<int> vals;
    long long time = 0;
public:
    Solution(ListNode* head) {
        while(head != nullptr) {
            this->vals.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        srand(time++);
        return this->vals[rand() % this->vals.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */



#endif //PROBLEM382_H
