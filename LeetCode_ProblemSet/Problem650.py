class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        cur = 2
        while n > 1:
            while n % cur == 0:
                count += cur
                n /= cur
            cur += 1
        return count