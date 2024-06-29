class Solution(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        adj = self.get_adj(n, edges)
        
        return [
            sorted(self.bfs(node, adj))
            for node in range(n)
        ]
        
    def get_adj(self, n, edges):
        adj = [
            [] for _ in range(n)
        ]

        for edge in edges:
            adj[edge[1]].append(edge[0])
            
        return adj
    
    def bfs(self, src, adj):
        visited = [False] * len(adj)
        q = [src]
        visited[src] = True
        ancestors = [src]
        
        while len(q) != 0:
            node = q[0]
            q = q[1:]
            
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append(neighbor)
                    ancestors.append(neighbor)
                    
        return ancestors[1:]