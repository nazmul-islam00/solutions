from collections import deque

class Solution(object):
    def countSubIslands(self, grid1, grid2):
        """
        :type grid1: List[List[int]]
        :type grid2: List[List[int]]
        :rtype: int
        """
        islands = self.getIslands(grid2)
        return self.getSubIslandCount(grid1, islands)
    
    def getSubIslandCount(self, grid, islands):
        count = 0
        for island in islands:
            isSubIsland = True
            for x, y in island:
                if grid[x][y] == 0:
                    isSubIsland = False
                    break
            if isSubIsland:
                count += 1
        return count
        
    def getIslands(self, grid):
        m, n = len(grid), len(grid[0])
        islands = []
        q = deque()
        
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 0:
                    continue
                    
                island = [(row, col)]
                grid[row][col] = 0
                q.append((row, col))
                
                while len(q) > 0:
                    r, c = q.popleft()
                    for n_r, n_c in self.getNeighbors(r, c, m, n):
                        if grid[n_r][n_c] == 0:
                            continue
                        grid[n_r][n_c] = 0
                        island.append((n_r, n_c))
                        q.append((n_r, n_c))
                            
                islands.append(island)
                                
        return islands
                        
                        
    def getNeighbors(self, r, c, m, n):
        change_x = [-1, 0, 0, 1]
        change_y = [0, -1, 1, 0]
        neighbors = []
        
        for x, y in zip(change_x, change_y):
            if 0 <= r + x < m and 0 <= c + y < n:
                neighbors.append((r + x, c + y))
                
        return neighbors