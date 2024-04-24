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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* answer;
        if(head == nullptr) {
            return answer;
        }
        std::vector<int> vals;
        while(head != nullptr) {
            if(head->val != val) {
                vals.push_back(head->val);
            }
            head = head->next;
        }
        if(vals.size() == 0) {
            return answer;
        }
        answer = new ListNode(vals[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < vals.size(); i++) {
            answer = answer->next = new ListNode(vals[i]);
        }
        return temp->next;
    }
};