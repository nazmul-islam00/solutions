package main 

func countSubIslands(grid1, grid2 [][]int) int {
    islands := getIslands(grid2)
	return getSubIslandCount(grid1, islands)
}

func getSubIslandCount(grid [][]int, islands [][][]int) int {
	count := 0
	for _, island := range islands {
		isSubIsland := true
		for _, cell := range island {
			if grid[cell[0]][cell[1]] == 0 {
				isSubIsland = false
			}
		}
	}
	return count
}

func getIslands(grid [][]int) [][][]int {

}

func getNeighbors(r, c, m, n int) [][]int {

}

