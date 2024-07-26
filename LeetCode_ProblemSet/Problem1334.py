class Solution(object):
    inf = 10e5

    def findTheCity(self, n, edges, distanceThreshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type distanceThreshold: int
        :rtype: int
        """
        distance = self.get_distance(n, edges)
        self.floyd_warshall(n, distance)
        neighbor_count = self.get_neighbor_count(n, distance, distanceThreshold)
        return self.get_intended_city(n, neighbor_count)
        
    def get_distance(self, n, edges):
        distance = [[self.inf for _ in range(n)] for _ in range(n)]
        
        for city in range(n):
            distance[city][city] = 0
        
        for edge in edges:
            city_1, city_2, weight = edge[0], edge[1], edge[2]
            distance[city_1][city_2] = weight
            distance[city_2][city_1] = weight
            
        return distance
    
    def floyd_warshall(self, n, distance):
        for intermediate_city in range(n):
            for city_1 in range(n):
                for city_2 in range(n):
                    distance[city_1][city_2] = min(
                        distance[city_1][city_2], 
                        distance[city_1][intermediate_city] + distance[intermediate_city][city_2]
                    )
    
    def get_neighbor_count(self, n, min_distance, threshold):
        neighbor_count = [0] * n
        
        for city_1 in range(n):
            for city_2 in range(n):
                if min_distance[city_1][city_2] <= threshold:
                    neighbor_count[city_1] = neighbor_count[city_1] + 1
                    
        return neighbor_count
    
    def get_intended_city(self, n, neighbor_count):
        intended_city, min_neighbors = -1, n
        

        for city in range(n):
            if neighbor_count[city] <= min_neighbors:
                min_neighbors = neighbor_count[city]
                intended_city = city

        return intended_city