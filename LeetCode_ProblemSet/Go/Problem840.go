package main

func numMagicSquaresInside(grid [][]int) int {
	count := 0
	for row := 0; row < len(grid) - 2; row++ {
		for col := 0; col < len(grid[0]) - 2; col++ {
			if magicSquare(grid, row, col) {
				count++
			}
		}
	}

	return count
}

func magicSquare(grid [][]int, rowStart, colStart int) bool {
	present := map[int]bool{}

	for row := rowStart; row < rowStart + 3; row++ {
		for col := colStart; col < colStart + 3; col++ {
			if grid[row][col] >= 1 && grid[row][col] <= 9 {

				if _, ok := present[grid[row][col]]; ok {
					return false
				} else {
					present[grid[row][col]] = true
				}

			} else {
				return false
			}
		}
	}

	grid00, grid01, grid02 := grid[rowStart][colStart], grid[rowStart][colStart + 1], grid[rowStart][colStart + 2]
	grid10, grid11, grid12 := grid[rowStart + 1][colStart], grid[rowStart + 1][colStart + 1], grid[rowStart + 1][colStart + 2]
	grid20, grid21, grid22 := grid[rowStart + 2][colStart], grid[rowStart + 2][colStart + 1], grid[rowStart + 2][colStart + 2]
			
	firstRowSum   := grid00 + grid01 + grid02
	secondRowSum  := grid10 + grid11 + grid12
	thirdRowSum   := grid20 + grid21 + grid22
	firstColSum   := grid00 + grid10 + grid20
	secondColSum  := grid01 + grid11 + grid21
	thirdColSum   := grid02 + grid12 + grid22
	firstDiagSum  := grid00 + grid11 + grid22
	secondDiagSum := grid02 + grid11 + grid20
			
	return  firstRowSum  == secondRowSum &&
			secondRowSum == thirdRowSum  &&
			thirdRowSum  == firstColSum  &&
			firstColSum  == secondColSum &&
			secondColSum == thirdColSum  &&
			thirdColSum  == firstDiagSum &&
			firstDiagSum == secondDiagSum
}