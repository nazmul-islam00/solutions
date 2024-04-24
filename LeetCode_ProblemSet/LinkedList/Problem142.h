#include <unordered_map>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *detectCycle(ListNode *head) {
        std::unordered_map<ListNode*, int> map;
        int pos = 0;
        while(head != nullptr) {
            auto it = map.find(head);
            if(it == map.end()) {
                map[head] = pos++;
                head = head->next;
            } else {
                return it->first;
            }
        }
        return nullptr;
    }
};