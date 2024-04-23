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
    ListNode* reverseList(ListNode* head) {
        ListNode* answer;
        if(head == nullptr) {
            return answer;
        }
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        answer = new ListNode(vals[vals.size() - 1]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = vals.size() - 2; i >= 0; i--) {
            answer = answer->next = new ListNode(vals[i]);
        }
        return temp->next;
    }
};