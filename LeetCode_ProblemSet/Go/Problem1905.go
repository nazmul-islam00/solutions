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
				break
			}
		}
		if isSubIsland {
			count++
		}
	}
	return count
}

func getIslands(grid [][]int) [][][]int {
	m, n := len(grid), len(grid[0])
	islands := [][][]int{}
	q := [][]int{}

	for row := 0; row < m; row++ {
		for col := 0; col < n; col++ {
			if grid[row][col] == 0 {
				continue
			}
			island := [][]int{[]int{row, col}}
			grid[row][col] = 0
			q = append(q, []int{row, col})

			for len(q) > 0 {
				cell := q[0]
				q = q[1:]
				for _, neighbor := range getNeighbors(cell[0], cell[1], m, n) {
					n_r, n_c := neighbor[0], neighbor[1]
					if grid[n_r][n_c] == 0 {
						continue
					}
					grid[n_r][n_c] = 0
					q = append(q, []int{n_r, n_c})
					island = append(island, []int{n_r, n_c})
				}
			}
			islands = append(islands, island)
		}
	}
	return islands
}

func getNeighbors(r, c, m, n int) [][]int {
	changeX := []int{-1, 0, 0, 1}
	changeY := []int{0, -1, 1, 0}
	neighbors := [][]int{}
	for i := 0; i < 4; i++ {
		if 0 <= r + changeX[i] && r + changeX[i] < m &&
			0 <= c + changeY[i] && c + changeY[i] < n {
			neighbors = append(neighbors, []int{r + changeX[i], c + changeY[i]})
		}
	}
	return neighbors
}