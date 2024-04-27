//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM2807_H
#define PROBLEM2807_H



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
    int gcd(int n1, int n2) {
        if(n1 > n2) {
            return gcd(n2, n1);
        }
        int rem = n2 % n1;
        while(rem != 0) {
            n2 = n1;
            n1 = rem;
            rem = n2 % n1;
        }
        return n1;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2 != nullptr) {
            temp1->next = new ListNode(gcd(temp1->val, temp2->val), temp2);
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return head;
    }
};



#endif //PROBLEM2807_H
