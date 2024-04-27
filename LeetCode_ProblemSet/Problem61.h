//
// Created by HP on 4/28/2024.
//

#ifndef PROBLEM61_H
#define PROBLEM61_H



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 0;
        ListNode* temp = head;
        ListNode* tail;
        while(temp != nullptr) {
            n++;
            tail = temp;
            temp = temp->next;
        }
        temp = head;
        int rotations = k % n;
        if(!rotations) {
            return head;
        }
        tail->next = head;
        for(int i = 0; i < n - rotations - 1; i++) {
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = nullptr;
        return ans;
    }
};



#endif //PROBLEM61_H
