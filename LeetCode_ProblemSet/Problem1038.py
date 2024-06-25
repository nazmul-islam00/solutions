# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def bstToGst(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.update(root, [0])
        return root
    
    def update(self, root, sum):
        if root is None:
            return
        
        self.update(root.right, sum)
        sum[0] += root.val
        root.val = sum[0]
        self.update(root.left, sum)
        
        