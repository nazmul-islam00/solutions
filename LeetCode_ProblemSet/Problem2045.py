from collections import deque
from math import floor


class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        """
        :type n: int
        :type edges: List[List[int]]
        :type time: int
        :type change: int
        :rtype: int
        """
        adj = self.get_adj(n, edges)
        dist = self.get_dist(n, adj)
        return self.get_time(dist, time, change)
        
    def get_time(self, dist, time, change):
        cur_time = 0
        
        for idx in range(1, dist + 1):
            turn = floor(cur_time / change)
            
            if turn % 2 == 0:
                cur_time += time
                
            else:
                cur_time = int(turn + 1) * change + time
        
        return cur_time
            
    def get_adj(self, n, edges):
        adj = {city: [] for city in range(1, n + 1)}
        
        for edge in edges:
            city_1, city_2 = edge[0], edge[1]
            adj[city_1].append(city_2)
            adj[city_2].append(city_1)
            
        return adj
    
    def get_dist(self, n, adj):
        dist = {city: [None, None] for city in range(1, n + 1)}
        dist[1][0] = 0
        q = deque()
        q.append((1, 0))

        while not q == deque():
            city, dis = q.popleft()
            
            for neighbor in adj[city]:
                if dist[neighbor][0] is None:
                    dist[neighbor][0] = dis + 1
                    q.append((neighbor, dis + 1))
                    
                elif dist[neighbor][1] is None:
                    if dist[neighbor][0] != dis + 1:
                        dist[neighbor][1] = dis + 1
                        
                    q.append((neighbor, dis + 1))
                    
        return dist[n][1]