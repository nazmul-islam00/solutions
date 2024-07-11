class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        # store indices of opening and closing parenthesis
        cur_openings = []
        indices = [0] * len(s)
        
        for i in range(len(s)):
            if s[i] == '(':
                cur_openings += [i]
            
            elif s[i] == ')':
                opening = cur_openings.pop()
                indices[opening] = i
                indices[i] = opening
                
        ans = ""
        direction = 1
        idx = 0
        
        while idx < len(s):
            if s[idx] == '(' or s[idx] == ')':
                idx = indices[idx]
                direction *= -1
                
            else:
                ans += s[idx]
                
            idx += direction

                
        return ans
                