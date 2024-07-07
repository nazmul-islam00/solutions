import math

class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        ans, empty = numBottles, numBottles
        
        while empty >= numExchange:
            ans += int(math.floor(empty / numExchange))
            empty = int(math.floor(empty / numExchange)) + (empty % numExchange)
            
        return ans