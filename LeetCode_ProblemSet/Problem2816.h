//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM2816_H
#define PROBLEM2816_H



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
    bool Double(ListNode* head) {
        if(head->next == nullptr) {
            if(head->val * 2 > 9) {
                head->val = (head->val * 2) % 10;
                return true;
            } else {
                head->val = head->val * 2;
                return false;
            }
        }
        bool flag = Double(head->next);
        if(head->val * 2 + flag > 9) {
            head->val = ((head->val * 2) + flag) % 10;
            return true;
        } else {
            head->val = ((head->val * 2) + flag) % 10;
            return false;
        }
        return false;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        bool addNode = Double(head);
        if(addNode) {
            ListNode* ans = new ListNode(1, head);
            head = ans;
        }
        return head;
    }
};



#endif //PROBLEM2816_H
