# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        start, end = head, head.next
        temp = None
        sum = 0
        
        while end is not None:
            sum += end.val

            if end.val == 0:
                start.val = sum
                temp = start
                start = start.next
                sum = 0

            end = end.next
            
        temp.next = None
        
        return head
        
        
        