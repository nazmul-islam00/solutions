//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM2_H
#define PROBLEM2_H
#include <vector>


/**
 * Definition for singly-linked list.
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        std::vector<int> sums;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val + l2->val + carry >= 10) {
                sums.push_back(l1->val + l2->val + carry - 10);
                carry = 1;
            } else {
                sums.push_back(l1->val + l2->val + carry);
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr) {
            if(l1->val + carry >= 10) {
                sums.push_back(l1->val + carry - 10);
                carry = 1;
            } else {
                sums.push_back(l1->val + carry);
                carry = 0;
            }
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            if(l2->val + carry >= 10) {
                sums.push_back(l2->val + carry - 10);
                carry = 1;
            } else {
                sums.push_back(l2->val + carry);
                carry = 0;
            }
            l2 = l2->next;
        }
        if(carry)
            sums.push_back(carry);
        std::vector<ListNode*> answer(sums.size());
        for(int i = 0; i < sums.size(); i++) {
            answer[i] = new ListNode(sums[i]);
        }
        for(int i = 0; i < sums.size() - 1; i++) {
            answer[i]->next = answer[i+1];
        }
        return answer[0];
    }
};



#endif //PROBLEM2_H
