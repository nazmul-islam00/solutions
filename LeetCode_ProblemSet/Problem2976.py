from string import ascii_lowercase

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
        costs = {
            ch1: {
                ch2: self.inf for ch2 in ascii_lowercase
            } for ch1 in ascii_lowercase
        }
        
        for ch in ascii_lowercase:
            costs[ch][ch] = 0
            
        for i in range(len(original)):
            costs[original[i]][changed[i]] = min(cost[i], costs[original[i]][changed[i]])
            
        for intermediate in ascii_lowercase:
            for ch1 in ascii_lowercase:
                for ch2 in ascii_lowercase:
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