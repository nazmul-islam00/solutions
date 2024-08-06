class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        count = {}
        for ch in word:
            count[ch] = count.get(ch, 0) + 1
            
        keys = [key for key in count]
        keys = sorted(keys, key=lambda ch: count[ch], reverse=True)
        
        cost = 0
        for idx in range(len(keys)):
            if idx < 8:
                cost += count[keys[idx]]
            elif idx < 16:
                cost += count[keys[idx]] * 2
            elif idx < 24:
                cost += count[keys[idx]] * 3
            else:
                cost += count[keys[idx]] * 4
                
        return cost