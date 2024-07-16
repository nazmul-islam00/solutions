# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
      
        
class Solution(object):
    def getDirections(self, root, startValue, destValue):
        """
        :type root: Optional[TreeNode]
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        nodes, parents = self.get_nodes_and_parents(root)
        source, destination = nodes[startValue], nodes[destValue]
        path_parents = self.bfs(source, destination, parents)
        return self.get_path(source, destination, path_parents)
        
    def get_nodes_and_parents(self, root):
        parents = {root: None}
        nodes = {}
        stack = [root]
        
        while len(stack) > 0:
            node = stack.pop()
            nodes[node.val] = node
            if node.left is not None:
                stack.append(node.left)
                parents[node.left] = node
            if node.right is not None:
                stack.append(node.right)
                parents[node.right] = node
                
        return nodes, parents
        
    def bfs(self, source, destination, parents):
        visited = {}
        frontiers = [source]
        path_parents = {source: None}
        
        while len(frontiers) > 0:
            node = frontiers.pop()
            visited[node] = True
            
            if node == destination:
                break
            
            if node.left is not None and node.left not in visited:
                frontiers.append(node.left)
                path_parents[node.left] = node
                
            if node.right is not None and node.right not in visited:
                frontiers.append(node.right)
                path_parents[node.right] = node
                
            if parents[node] is not None and parents[node] not in visited:
                frontiers.append(parents[node])
                path_parents[parents[node]] = node
                
        return path_parents
    
    def get_path(self, source, destination, path_parents):
        path, node = "", destination
        
        while node != source:
            predecessor = path_parents[node]
            
            if node == predecessor.left:
                path += "L"
            elif node == predecessor.right:
                path += "R"
            else:
                path += "U"
                
            node = predecessor
            
        return path[::-1]
                