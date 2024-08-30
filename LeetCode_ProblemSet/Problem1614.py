class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_depth, cur_depth = 0, 0
        for ch in s:
            if ch == "(":
                cur_depth += 1
                max_depth = max(max_depth, cur_depth)
            elif ch == ")":
                cur_depth -= 1
        return max_depth