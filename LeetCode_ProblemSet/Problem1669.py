# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
        
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        list2_head, list2_tail = list2, list2
        while list2_tail.next is not None:
            list2_tail = list2_tail.next
            
        ans, pre, post = list1, list1, list1
        for _ in range(a - 1):
            pre = pre.next
        for _ in range(b + 1):
            post = post.next   
            
        pre.next = list2_head
        list2_tail.next = post 
        
        return ans     
        
        