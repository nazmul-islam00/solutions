//
// Created by HP on 4/16/2024.
//

#ifndef PROBLEM141_H
#define PROBLEM141_H



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_map<ListNode*, int> map;
        int count = 0;
        while(head != nullptr) {
            if(map.find(head) != map.end())
                return true;
            map[head] = count++;
            head = head->next;
        }
        return false;
    }
};



#endif //PROBLEM141_H
