class Solution(object):
    def makeGood(self, s):
        """
        :type s: str
        :rtype: str
        """
        idx = 0
        while idx < len(s) - 1:
            if (
                (s[idx].islower() and s[idx].upper() == s[idx + 1]) or 
                (s[idx].isupper() and s[idx].lower() == s[idx + 1])
            ):
                s = s[:idx] + s[idx + 2:]
                idx = max(idx - 1, 0)
            else:
                idx += 1
        return s        