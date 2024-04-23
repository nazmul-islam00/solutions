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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr) {
            return list1;
        }
        std::vector<int> nums;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                nums.push_back(list1->val);
                list1 = list1->next;
            } else {
                nums.push_back(list2->val);
                list2 = list2->next;
            }
        }  
        while(list1 != nullptr) {
            nums.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2 != nullptr) {
            nums.push_back(list2->val);
            list2 = list2->next;
        }
        ListNode* answer;
        if(nums.size() == 0) {
            return answer;
        }
        answer = new ListNode(nums[0]);
        ListNode* temp = new ListNode(-1, answer);
        for(int i = 1; i < nums.size(); i++) {
            answer = answer->next = new ListNode(nums[i]);
        }
        return temp->next;
    }
};