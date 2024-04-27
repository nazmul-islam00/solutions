//
// Created by HP on 4/28/2024.
//

#ifndef PROBLEM2095_H
#define PROBLEM2095_H



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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) {
            return head->next;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }
        temp = head;
        int moves = floor(n / 2) - 1;
        for(int i = 0; i < moves; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};



#endif //PROBLEM2095_H
