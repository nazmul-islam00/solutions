package main 

func regionsBySlashes(grid []string) int {
    graph := generateGraph(grid)
	return getRegionCount(graph)
}

func generateGraph(grid []string) [][]int {
	rows, cols := len(grid) * 3, len(grid) * 3
	graph := make([][]int, rows)
	for i := 0; i < rows; i++ {
		graph[i] = make([]int, cols)
	}
	
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid); j++ {
			if grid[i][j] == '/' {
				graph[3 * i][3 *j + 2] = 1
				graph[3 * i + 1][3 * j + 1] = 1
				graph[3 * i + 2][3 * j] = 1
			} else if grid[i][j] == '\\' {
				graph[3 * i][3 *j] = 1
				graph[3 * i + 1][3 * j + 1] = 1
				graph[3 * i + 2][3 * j + 2] = 1
			}
		}
	}
 
	return graph
}

func getRegionCount(graph [][]int) int {
	regionCount := 0

	for i := 0; i < len(graph); i++ {
		for j := 0; j < len(graph); j++ {
			if graph[i][j] == 0 {
				bfs(graph, i, j)
				regionCount++
			}
		}
 	}

	return regionCount
}

func bfs(graph [][]int , srcX, srcY int) {
	q := [][]int{{srcX, srcY}}
	graph[srcX][srcY] = 1
	changeX := []int{-1, 0, 0, 1}
	changeY := []int{0, -1, 1, 0}

	for len(q) > 0 {
		cell := q[0]
		q = q[1:]
		x, y := cell[0], cell[1]
		for i := 0; i < 4; i++ {
			neighborX, neighborY := x + changeX[i], y + changeY[i]
			if  0 <= neighborX && neighborX < len(graph) && 
				0 <= neighborY && neighborY < len(graph) &&
				graph[neighborX][neighborY] == 0 {
					graph[neighborX][neighborY] = 1
					q = append(q, []int{neighborX, neighborY})
			}
		}
 	}
}