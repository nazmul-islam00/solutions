/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode list2_head = list2, list2_tail = list2;
        ListNode pre = list1, post = list1, ans = list1;

        while (list2_tail.next != null) 
            list2_tail = list2_tail.next;
        for (int i = 0; i < a - 1; i++) 
            pre = pre.next; 
        for (int i = 0; i < b + 1; i++) 
            post = post.next;

        pre.next = list2_head;
        list2_tail.next = post;
        return ans;
    }
}