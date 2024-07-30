class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        cost = 0
        count_b = 0
        
        for ch in s:
            if ch == 'b':
                count_b += 1
            else:
                # to remove 'b' cost will be count_b
                # to remove 'a' cost is just additional 1
                cost = min(cost + 1, count_b)
                
        return cost