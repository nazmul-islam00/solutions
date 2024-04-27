//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM2130_H
#define PROBLEM2130_H
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
    int pairSum(ListNode* head) {
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        int maxSum = 0;
        for(int i = 0; i < vals.size() / 2; i++) {
            maxSum = max(maxSum, vals[i] + vals[vals.size() - i - 1]);
        }
        return maxSum;
    }
};



#endif //PROBLEM2130_H
