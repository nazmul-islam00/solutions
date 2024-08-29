class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(filter(lambda x: len(x) > 0, s.split(" "))[-1])
        