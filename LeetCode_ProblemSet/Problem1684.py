class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        allowed = set(allowed)
        count = 0
        for word in words:
            allow = True
            for ch in word:
                if ch not in allowed:
                    allow = False
                    break
            if allow:
                count += 1
        return count