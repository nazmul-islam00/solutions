from collections import deque


class Solution(object):
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        graph = self.generateGraph(grid)
        return self.getRegionCount(graph)
        
    def generateGraph(self, grid):
        rows = len(grid) * 3
        cols = len(grid) * 3
        graph = [[0 for _ in range(cols)] for _ in range(rows)]
        
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] == '/':
                    graph[3 * i][3 * j + 2] = 1
                    graph[3 * i + 1][3 * j + 1] = 1
                    graph[3 * i + 2][3 * j] = 1
                elif grid[i][j] == '\\':
                    graph[3 * i][3 * j] = 1
                    graph[3 * i + 1][3 * j + 1] = 1  
                    graph[3 * i + 2][3 * j + 2] = 1
                                
        return graph
    
    def getRegionCount(self, graph):
        regionCount = 0
        
        for i in range(len(graph)):
            for j in range(len(graph)):
                if graph[i][j] == 0:
                    self.bfs(graph, [i, j])
                    regionCount += 1
                    
        return regionCount
        
    def bfs(self, graph, src):
        q = deque()
        q.append(src)
        srcX, srcY = src
        graph[srcX][srcY] = 1
        changeX = [-1, 0, 0, 1]
        changeY = [0, -1, 1, 0]
        
        while len(q) > 0:
            x, y = q.popleft()
            for i in range(4):
                neighborX, neighborY = x + changeX[i], y + changeY[i]
                if (0 <= neighborX < len(graph) and 
                    0 <= neighborY < len(graph) and 
                    graph[neighborX][neighborY] == 0):
                    graph[neighborX][neighborY] = 1
                    q.append([neighborX, neighborY])