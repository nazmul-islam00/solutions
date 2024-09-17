from collections import Counter

class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        count1 = dict(Counter(s1.split(" ")))
        count2 = dict(Counter(s2.split(" ")))
        return [
            word for word in count1
            if count1[word] == 1 and word not in count2
        ] + [
            word for word in count2
            if count2[word] == 1 and word not in count1
        ]