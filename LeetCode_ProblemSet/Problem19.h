#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        std::vector<int> removedVals;
        for(int i = 0; i < vals.size(); i++) {
            if(i != vals.size() - n) {
                removedVals.push_back(vals[i]);
            }
        }
        std::cout << removedVals.size() << std::endl;
        ListNode* answer;
        if(!removedVals.size()) {
            return answer;
        }
        answer = new ListNode(removedVals[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < removedVals.size(); i++) {
            answer = answer->next = new ListNode(removedVals[i]);
        }
        return temp->next;
    }
};