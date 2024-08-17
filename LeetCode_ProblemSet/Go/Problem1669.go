package main 

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	list2_head, list2_tail := list2, list2
	for list2_tail.Next != nil {
		list2_tail = list2_tail.Next
	}

	pre, post, ans := list1, list1, list1
	for i := 0; i < a - 1; i++ {
		pre = pre.Next
	}
	for i := 0; i < b + 1; i++ {
		post = post.Next
	}

	pre.Next = list2_head
	list2_tail.Next = post

	return ans
}