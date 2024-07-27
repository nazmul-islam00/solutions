class Solution(object):
    inf = 10e8
    
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        costs = self.floyd_warshall(original, changed, cost)
        return self.find_cost(source, target, costs)
    
    def floyd_warshall(self, original, changed, cost):
        costs = [[self.inf for _ in range(26)] for _ in range(26)]
        
        for i in range(26):
            costs[i][i] = 0
            
        for i in range(len(original)):
            costs[original[i] - 'a'][changed[i] - 'a'] = cost[i]
            
        for intermediate in range(26):
            for ch1 in range(26):
                for ch2 in range(26):
                    costs[ch1][ch2] = min(
                        costs[ch1][ch2],
                        costs[ch1][intermediate] + costs[intermediate][ch2]
                    )
        
        return costs
    
    def find_cost(self, source, target, costs):
        cost = 0
        
        for i in range(len(source)):
            if costs[source[i]][target[i]] == self.inf:
                return -1
            
            else:
                cost += costs[source[i]][target[i]]
                    
        return cost