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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < vals.size() / 2; i++) {
            int temp = vals[2 * i];
            vals[2 * i] = vals[2 * i + 1];
            vals[2 * i + 1] = temp;
        }
        ListNode* answer = new ListNode(vals[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < vals.size(); i++) {
            answer = answer->next = new ListNode(vals[i]);
        }
        return temp->next;
    }
};