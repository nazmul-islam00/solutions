class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        if bits[-1] == 1: 
            return False
        if len(bits) == 1:
            return True
        if bits[-2] == 0:
            return True
        
        cnt = 0
        idx = len(bits) - 2
        while idx >= 0:
            if bits[idx] == 1:
                cnt += 1
            else: 
                break
            idx -= 1

        if cnt % 2 == 0:
            return True
        return False

        