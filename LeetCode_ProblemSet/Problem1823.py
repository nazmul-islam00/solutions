class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        # initialize position
        pos = 0
        
        # iterate n - 1 times
        for i in range(2, n + 1):
            # move to k-th friend and then start from the next
            pos = (pos + k) % i
            
        # 1-based index
        return pos + 1