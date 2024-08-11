from collections import deque

class Solution(object):
    def minDays(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        regionCount = self.getRegionCount(grid)
        if regionCount != 1:
            return 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    regionCount = self.getRegionCount(grid)
                    if regionCount != 1:
                        return 1
                    grid[i][j] = 1
        
        return 2
        
    def getRegionCount(self, grid):
        regionCount = 0
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and not visited[i][j]:
                    self.bfs(grid, visited, i, j)
                    regionCount += 1
                    
        return regionCount 
        
    def bfs(self, grid, visited,  srcX, srcY):
        q = deque()
        q.append((srcX, srcY))
        visited[srcX][srcY] = True
        neighborX = [-1, 0, 0, 1]
        neighborY = [0, -1, 1, 0]
        
        while len(q) > 0:
            x, y = q.popleft()
            for i in range(4):
                neighborx, neighbory = x + neighborX[i], y + neighborY[i]
                if (0 <= neighborx < len(grid) and 
                    0 <= neighbory < len(grid[0]) and 
                    grid[neighborx][neighbory] == 1 and
                    not visited[neighborx][neighbory]):
                    visited[neighborx][neighbory] = True
                    q.append([neighborx, neighbory])