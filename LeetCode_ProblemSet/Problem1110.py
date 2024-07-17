# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        # nothing to delete
        if to_delete == []:
            return [root]
        if root is None:
            return []
        
        to_delete = {key: 1 for key in to_delete}
        nodes = self.get_nodes(root, [])
        return self.get_roots(root, to_delete, nodes)
        
    def get_roots(self, root, to_delete, nodes):
        rootList = []
        for node in nodes:
            has_left = node.left is not None and node.left.val not in to_delete
            has_right = node.right is not None and node.right.val not in to_delete
            
            if node.val in to_delete:
                if not has_left and not has_right:
                    pass
                if has_left:
                    rootList.append(node.left)
                if has_right:
                    rootList.append(node.right)
                    
            else:
                if not has_left:
                    node.left = None
                if not has_right:
                    node.right = None

        if root.val not in to_delete:
            rootList.append(root)
            
        return rootList
                
        
    def get_nodes(self, root, nodes):
        if root.left is not None:
           self.get_nodes(root.left, nodes)
        if root.right is not None:
            self.get_nodes(root.right, nodes)
        nodes.append(root)
        return nodes 