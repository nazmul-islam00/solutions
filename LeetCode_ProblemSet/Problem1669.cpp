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
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *list2_head, *list2_tail;
        ListNode *pre, *post, *ans;
        list2_head = list2_tail = list2;
        pre = post = ans = list1;

        while (list2_tail->next != nullptr) 
            list2_tail = list2_tail -> next;
        for (int i = 0; i < a - 1; i++)
            pre = pre -> next;
        for (int i = 0; i < b + 1; i++)
            post = post->next;

        pre->next = list2_head;
        list2_tail->next = post;
        return ans;
    }
};