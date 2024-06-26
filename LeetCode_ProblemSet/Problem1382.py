# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        nodes = []
        self.get_nodes(root, nodes)
        return self.form_tree(nodes, 0, len(nodes) - 1)
    
    def form_tree(self, nodes, low, high):
        """Forms a binary tree in the given range."""
        if low > high:
            return None
        
        mid = low + (high - low) // 2  
        left = self.form_tree(nodes, low, mid - 1)
        right = self.form_tree(nodes, mid + 1, high)
        node =  TreeNode(nodes[mid], left, right) 
        
        return node  
        
    def get_nodes(self, root, nodes):
        """Returns the nodes in-order."""
        if root is None:
            return 
        
        self.get_nodes(root.left, nodes)
        nodes.append(root.val)
        self.get_nodes(root.right, nodes)