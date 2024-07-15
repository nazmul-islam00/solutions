# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def createBinaryTree(self, descriptions):
        """
        :type descriptions: List[List[int]]
        :rtype: Optional[TreeNode]
        """
        nodes, parents, children = {}, {}, {}
            
        for description in descriptions:
            parent, child, is_left = description
            parents[parent] = 0
            children[child] = 0
            
            if parent in nodes:
                parent_node = nodes[parent] 
            else:
                parent_node = TreeNode(parent)
                nodes[parent] = parent_node
                
            if child in nodes:
                child_node = nodes[child] 
            else:
                child_node = TreeNode(child)
                nodes[child] = child_node
                
            if is_left == 1:
                parent_node.left = child_node
            else:
                parent_node.right = child_node
                
        for parent in parents.keys():
            if parent not in children:
                return nodes[parent]