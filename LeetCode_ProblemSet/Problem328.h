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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        std::vector<int> vals;
        while(head) {
            vals.push_back(head->val);
            head = head->next;
        }
        std::vector<int> reorderedVals;
        for(int i = 0; i < vals.size(); i += 2) {
            reorderedVals.push_back(vals[i]);
        }
        for(int i = 1; i < vals.size(); i += 2) {
            reorderedVals.push_back(vals[i]);
        }
        ListNode* answer = new ListNode(reorderedVals[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < reorderedVals.size(); i++) {
            answer = answer->next = new ListNode(reorderedVals[i]);
        }
        return temp->next;
    }
};