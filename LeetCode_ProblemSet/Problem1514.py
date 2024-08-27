from heapq import heappop, heappush, heapify

class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        """
        :type n: int
        :type edges: List[List[int]]
        :type succProb: List[float]
        :type start_node: int
        :type end_node: int
        :rtype: float
        """
        cost = {i: {} for i in range(n)}
        adj = [[] for _ in range(n)]
        probs = [0 for _ in range(n)]
        probs[start_node] = 1
        
        for [node1, node2], prob in zip(edges, succProb):
            cost[node1][node2] = prob
            cost[node2][node1] = prob 
            adj[node1].append(node2)
            adj[node2].append(node1)
         
        heap = []
        heapify(heap)  
        
        heappush(heap, (-1, start_node))
        while len(heap) > 0:
            prob, node = heappop(heap)
            if node == end_node:
                return -prob
            
            for neighbor in adj[node]:
                if -prob * cost[node][neighbor] > probs[neighbor]:
                    probs[neighbor] = -prob * cost[node][neighbor]
                    heappush(heap, (-probs[neighbor], neighbor))
                    
        return 0      