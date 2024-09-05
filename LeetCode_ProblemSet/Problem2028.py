class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        req = (len(rolls) + n) * mean - sum(rolls)
        
        if req > 6 * n or req < n:
            return []
        
        common = req // n
        req -= common * n
        
        return [common] * (n - req) + [common + 1] * req