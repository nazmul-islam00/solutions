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
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        std::vector<int> reversedVals(vals.size());
        int reversed = vals.size() / k;
        int currIndex = -1;
        int reverseIndex = 0;
        for(int i = 0; i < reversed; i++) {
            for(int j = currIndex + k; j > currIndex; j--) {
                reversedVals[reverseIndex++] = vals[j];
            }
            currIndex += k;
        }
        for(int i = currIndex + 1; i < vals.size(); i++) {
            reversedVals[i] = vals[i];
        }
        ListNode* answer = new ListNode(reversedVals[0]);
        ListNode* temp = new ListNode(1, answer);
        for(int i = 1; i < reversedVals.size(); i++) {
            answer = answer->next = new ListNode(reversedVals[i]);
        }
        return temp->next;
    }
};