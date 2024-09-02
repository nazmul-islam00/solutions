class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        i = 0
        l = len(chalk)
        k %= sum(chalk)
        while True:
            if chalk[i] > k:
                return i
            k -= chalk[i]
            i = (i + 1) % l