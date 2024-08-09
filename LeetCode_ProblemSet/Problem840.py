class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        for row in range(len(grid) - 2):
            for col in range(len(grid[0]) - 2):
                if self.magicSquare(grid, row, col):
                    count += 1
        
        return count
    
    def magicSquare(self, grid, rowStart, colStart):
        present = {}
        
        for row in range(rowStart, rowStart + 3):
            for col in range(colStart, colStart + 3):
                if 1 <= grid[row][col] <= 9:
                    
                    if grid[row][col] in present:
                        return False
                    else:
                        present[grid[row][col]] = True
                        
                else:
                    return False
                
        grid00, grid01, grid02 = grid[rowStart][colStart], grid[rowStart][colStart + 1], grid[rowStart][colStart + 2]
        grid10, grid11, grid12 = grid[rowStart + 1][colStart], grid[rowStart + 1][colStart + 1], grid[rowStart + 1][colStart + 2]
        grid20, grid21, grid22 = grid[rowStart + 2][colStart], grid[rowStart + 2][colStart + 1], grid[rowStart + 2][colStart + 2]
                
        firstRowSum   = grid00 + grid01 + grid02
        secondRowSum  = grid10 + grid11 + grid12
        thirdRowSum   = grid20 + grid21 + grid22
        firstColSum   = grid00 + grid10 + grid20
        secondColSum  = grid01 + grid11 + grid21
        thirdColSum   = grid02 + grid12 + grid22
        firstDiagSum  = grid00 + grid11 + grid22
        secondDiagSum = grid02 + grid11 + grid20
                
        return firstRowSum == secondRowSum == thirdRowSum == firstColSum == secondColSum == thirdColSum == firstDiagSum == secondDiagSum