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
    void reorderList(ListNode* head) {
        std::vector<ListNode*> nodes;
        ListNode* temp = head;
        while(temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        for(int i = 0; i < nodes.size() / 2; i++) {
            nodes[nodes.size() - 1 - i]->next = nodes[i]->next;
            nodes[i]->next = nodes[nodes.size() - 1 - i];
        }
        nodes[nodes.size() / 2]->next = nullptr;
    }
};