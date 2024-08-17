#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *list2_head = list2, *list2_tail = list2;
    struct ListNode *pre = list1, *post = list1, *ans = list1;

    while (list2_tail->next != NULL) {
        list2_tail = list2_tail->next;
    }
    for (int i = 0; i < a - 1; i++) {
        pre = pre->next;
    }
    for (int i = 0; i < b + 1; i++) {
        post = post->next;
    }

    pre->next = list2_head;
    list2_tail->next = post;
    return ans;
}