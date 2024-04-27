//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM1721_H
#define PROBLEM1721_H


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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == nullptr) {
            return head;
        }
        ListNode* temp1 = head;
        int n = 0;
        while(temp1 != nullptr) {
            n++;
            temp1 = temp1->next;
        }
        int fromStart = k - 1;
        int fromEnd = n - k;
        ListNode* temp2 = temp1 = head;
        for(int i = 0; i < fromStart; i++) {
            temp1 = temp1->next;
        }
        for(int i = 0; i < fromEnd; i++) {
            temp2 = temp2->next;
        }
        int temp = temp1->val;
        temp1->val = temp2->val;
        temp2->val = temp;
        return head;
    }
};



#endif //PROBLEM1721_H
