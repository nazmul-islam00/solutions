class Solution(object):
    def minHeightShelves(self, books, shelfWidth):
        """
        :type books: List[List[int]]
        :type shelfWidth: int
        :rtype: int
        """
        memo = {}
        def solve(idx):
            if idx == len(books):
                return 0
            
            if idx in memo:
                return memo[idx]
            
            cur_width = shelfWidth
            cur_height = 0
            memo[idx] = float("inf")
            
            for j in range(idx, len(books)):
                width, height = books[j]
                
                if cur_width < width:
                    break
                
                cur_width -= width
                cur_height = max(cur_height, height)
                memo[idx] = min (
                    memo[idx],
                    cur_height + solve(j + 1)
                )
                
            return memo[idx]
                
        
        return solve(0)