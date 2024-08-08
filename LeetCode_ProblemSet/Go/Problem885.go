package main

func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
    cell_count := rows * cols
	next_direction := map[string]string{
		"Right": "Down",
		"Down" : "Left",
		"Left" : "Up",
		"Up"   : "Right",
	}
	cur_direction := "Right"
	cur_radius := 1
	cur_radius_time := 0
	cells_encountered := [][]int{
		{rStart, cStart},
	}
	row, col := rStart, cStart

	for {
		for range cur_radius {
			switch cur_direction {
			case "Right": col++
			case "Down" : row++
			case "Left" : col--
			case "Up"   : row--
			}

			if row >= 0 && row < rows && col >= 0 && col < cols {
				cells_encountered = append(cells_encountered, []int{row, col})
			}
		}

		if len(cells_encountered) == cell_count {
			break
		}

		cur_direction = next_direction[cur_direction]
		cur_radius_time++
		if cur_radius_time == 2 {
			cur_radius_time = 0
			cur_radius++
		}
	}

	return cells_encountered
}