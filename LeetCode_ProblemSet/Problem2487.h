//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM2487_H
#define PROBLEM2487_H
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
    ListNode* removeNodes(ListNode* head) {
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        std::vector<bool> taken(vals.size(), false);
        int currMax = vals[vals.size() - 1];
        taken[taken.size() - 1] = true;
        for(int i = vals.size() - 2; i >= 0; i--) {
            if(vals[i] >= currMax) {
                currMax = vals[i];
                taken[i] = true;
            }
        }
        int ind = 0;
        for(; ind < vals.size(); ind++) {
            if(taken[ind]) {
                break;
            }
        }
        ListNode* answer = new ListNode(vals[ind++]);
        ListNode* temp = new ListNode(-1, answer);
        for(; ind < vals.size(); ind++) {
            if(taken[ind]) {
                answer = answer->next = new ListNode(vals[ind]);
            }
        }
        return temp->next;
    }
};



#endif //PROBLEM2487_H
