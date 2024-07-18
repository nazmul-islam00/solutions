from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution(object):
    def countPairs(self, root, distance):
        """
        :type root: TreeNode
        :type distance: int
        :rtype: int
        """
        leaves = self.get_leaves(root)
        parents = self.get_parents(root)
        return sum([
            self.bfs(parents, leaf, distance)
            for leaf in leaves
        ]) // 2
        
    def get_leaves(self, root):
        leaves = set()
        stack = [root]
        
        while len(stack) > 0:
            node = stack.pop()
            
            if node.left is None and node.right is None:
                leaves.add(node)
            if node.left is not None:
                stack.append(node.left)
            if node.right is not None:
                stack.append(node.right)
                
        return leaves
            
    def get_parents(self, root):
        parents = {root: None}
        stack = [root]
        
        while len(stack) > 0:   
            node = stack.pop()
            
            if node.left is not None:
                parents[node.left] = node
                stack.append(node.left)
            if node.right is not None:
                parents[node.right] = node
                stack.append(node.right)
                
        return parents
    
    def bfs(self, parents, src, distance):
        visited = set()
        visited.add(src)
        q = deque()
        q.append((src, 0))
        count = 0
        
        while len(q) > 0:
            node, depth = q.popleft()
            
            if depth > distance:
                break
            if node.left is None and node.right is None:
                count += 1
            if node.left is not None and node.left not in visited:
                q.append((node.left, depth + 1))
                visited.add(node.left)
            if node.right is not None and node.right not in visited:
                q.append((node.right, depth + 1))
                visited.add(node.right)
            if parents[node] is not None and parents[node] not in visited:
                q.append((parents[node], depth + 1))
                visited.add(parents[node])
                
        return count - 1