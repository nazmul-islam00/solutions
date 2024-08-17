/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeInBetween(list1: ListNode | null, a: number, b: number, list2: ListNode | null): ListNode | null {
    let list2_head: ListNode | null = list2, list2_tail: ListNode | null = list2;
    while (list2_tail.next !== null) {
        list2_tail = list2_tail.next;
    }

    let pre: ListNode | null = list1, post: ListNode | null = list1, ans: ListNode | null = list1;
    for (let i = 0; i < a - 1; i++) {
        pre = pre.next;
    }
    for (let i = 0; i < b + 1; i++) {
        post = post.next;
    }

    pre.next = list2_head;
    list2_tail.next = post;

    return ans;
};