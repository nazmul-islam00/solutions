"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        nodes = []
        self.postorderHelp(root, nodes)
        return nodes
        
        
    def postorderHelp(self, root, nodes):
        if root is None:
            return 

        for child in root.children:
            self.postorderHelp(child, nodes)
            
        nodes.append(root.val)