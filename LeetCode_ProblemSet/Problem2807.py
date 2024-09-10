# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution(object):
    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        def gcd(n1, n2):
            if n1 > n2:
                return gcd(n2, n1)
            while n2 % n1 != 0:
                n2, n1 = n1, n2 % n1
            return n1
        
        ans = head
        while head.next is not None:
            head.next = ListNode(gcd(head.val, head.next.val), head.next)
            head = head.next.next
        return ans
        