# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        nums = set(nums)
        while True:
            if head.val in nums:
                head = head.next
            if head is None or head.val not in nums:
                break
        ans = head
        while head is not None:
            while head.next is not None and head.next.val in nums:
                head.next = head.next.next
            head = head.next
        return ans