/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function(list1, a, b, list2) {
    let list2_head = list2, list2_tail = list2;
    let pre = list1, post = list1, ans = list1;

    while (list2_tail.next !== null) 
        list2_tail = list2_tail.next 
    for (let i = 0; i < a - 1; i++) 
        pre = pre.next
    for (let i = 0; i < b + 1; i++)
        post = post.next

    pre.next = list2_head;
    list2_tail.next = post;
    return ans;
};