class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) <= 1 or self.isPalindrome(s):
            return s
        l: int = len(s)
        reversed: str = s[::-1]
        for i in range(len(s)):
            if s[:l - i] == reversed[i:]:
                return reversed[:i] + s
        
    def isPalindrome(self, s: str) -> bool:
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - i - 1]:
                return False
        return True
    
solution = Solution()
print(solution.shortestPalindrome("abbacd"))