import math


class Solution(object):
    def passThePillow(self, n, time):
        """
        :type n: int
        :type time: int
        :rtype: int
        """
        return (
            1 + time % (n - 1) if math.floor(time / (n - 1)) % 2 == 0
            else n - time % (n - 1)
        )