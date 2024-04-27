//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM725_H
#define PROBLEM725_H
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
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        std::vector<ListNode*> answer(k);
        if(vals.size() <= k) {
            for(int i = 0; i < vals.size(); i++) {
                answer[i] = new ListNode(vals[i]);
            }
            return answer;
        }
        int avg = vals.size() / k;
        int rem = vals.size() % k;
        int ind = 0;
        for(int i = 0; i < rem; i++) {
            ListNode* temp1 = new ListNode(vals[ind++]);
            ListNode* temp2 = new ListNode(-1, temp1);
            for(int j = 0; j < avg; j++) {
                temp1 = temp1->next = new ListNode(vals[ind++]);
            }
            answer[i] = temp2->next;
        }
        for(int i = rem; i < k; i++) {
            ListNode* temp1 = new ListNode(vals[ind++]);
            ListNode* temp2 = new ListNode(-1, temp1);
            for(int j = 1; j < avg; j++) {
                temp1 = temp1->next = new ListNode(vals[ind++]);
            }
            answer[i] = temp2->next;
        }
        return answer;
    }
};



#endif //PROBLEM725_H
