class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        maxAbility = max(worker)
        maxProfit = [0] * (maxAbility + 1)
        currMaxProfit = 0
        netProfit = 0
        
        
        for i in range(len(difficulty)):
            if difficulty[i] <= maxAbility:
                maxProfit[difficulty[i]] = max(maxProfit[difficulty[i]], profit[i])
                
        
        for i in range(len(maxProfit)):
            maxProfit[i] = currMaxProfit = max(maxProfit[i], currMaxProfit)
            
        for i in range(len(worker)):
            netProfit += maxProfit[worker[i]]
            
        return netProfit