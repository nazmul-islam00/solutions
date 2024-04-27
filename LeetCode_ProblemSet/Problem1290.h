//
// Created by HP on 4/28/2024.
//

#ifndef PROBLEM1290_H
#define PROBLEM1290_H



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
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head != nullptr) {
            res *= 2;
            res += head->val;
            head = head->next;
        }
        return res;
    }
};



#endif //PROBLEM1290_H
