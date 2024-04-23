#include <vector>
#include <unordered_map>

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
    int numComponents(ListNode* head, std::vector<int>& nums) {
        int num = 0;
        std::unordered_map<int, int> numMap;
        for(int x : nums) {
            numMap[x] = 1;
        }
        bool componentStarted = false;
        while(head != nullptr) {
            if(componentStarted) {
                if(numMap.find(head->val) == numMap.end()) {
                    componentStarted = false;
                }
            } else {
                if(numMap.find(head->val) != numMap.end()) {
                    componentStarted = true;
                    num++;
                }
            }
            head = head->next;
        }
        return num;
    }
};