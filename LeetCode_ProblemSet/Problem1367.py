# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
    
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: ListNode
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return False
        return self.isPath(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
        
    def isPath(self, head, root):
        if root is None:
            return False
        if root.val != head.val:
            return False
        if head.next is None:
            return True
        return self.isPath(head.next, root.left) or self.isPath(head.next, root.right)