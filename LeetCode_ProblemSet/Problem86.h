//
// Created by HP on 4/28/2024.
//

#ifndef PROBLEM86_H
#define PROBLEM86_H
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        std::vector<std::pair<int, bool>> vals;
        while(head != nullptr) {
            vals.push_back({head->val, false});
            head = head->next;
        }
        std::vector<int> partitionedVals;
        for(int i = 0; i < vals.size(); i++) {
            if(vals[i].first < x) {
                partitionedVals.push_back(vals[i].first);
                vals[i].second = true;
            }
        }
        for(int i = 0; i < vals.size(); i++) {
            if(!vals[i].second) {
                partitionedVals.push_back(vals[i].first);
            }
        }
        ListNode* answer = new ListNode(partitionedVals[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < partitionedVals.size(); i++) {
            answer = answer->next = new ListNode(partitionedVals[i]);
        }
        return temp->next;
    }
};



#endif //PROBLEM86_H
