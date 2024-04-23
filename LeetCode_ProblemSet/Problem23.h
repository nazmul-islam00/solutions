#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::vector<int> sortedValues;
        for(ListNode* list : lists) {
            while(list != nullptr) {
                sortedValues.push_back(list->val);
                list = list->next;
            }
        }
        std::sort(sortedValues.begin(), sortedValues.end());
        ListNode* answer;
        if(!sortedValues.size()) {
            return answer;
        }
        answer = new ListNode(sortedValues[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < sortedValues.size(); i++) {
            answer = answer->next = new ListNode(sortedValues[i]);;
        }
        return temp->next;
    }
};