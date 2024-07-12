class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        if x > y:
            gain_1, stack = self.check(s, "ab", x)
            gain_2, stack = self.check("".join(stack), "ba", y)
        
        else:
            gain_1, stack = self.check(s, "ba", y)
            gain_2, stack = self.check("".join(stack), "ab", x)
            
        return gain_1 + gain_2
    
    def check(self, s, str, val):
        gain, stack = 0, []
        
        for ch in s:
            if ch == str[1] and len(stack) >=1 and stack[-1] == str[0]:
                stack.pop()
                gain += val
                
            else:
                stack.append(ch)
                
        return gain, stack