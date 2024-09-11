class Solution(object):
    def minBitFlips(self, start, goal):
        """
        :type start: int
        :type goal: int
        :rtype: int
        """
        start, goal = bin(start)[2:], bin(goal)[2:]
        l = max(len(start), len(goal))
        start, goal = start.rjust(l, "0"), goal.rjust(l, "0")
        return sum([1 for i in range(l) if start[i] != goal[i]])