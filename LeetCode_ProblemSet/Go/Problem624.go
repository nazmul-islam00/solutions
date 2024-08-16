package main

import "math"

func maxDistance(arrays [][]int) int {
	smallest, largest := arrays[0][0], arrays[0][len(arrays[0]) - 1]
	maxDist := 0
	for idx := 1; idx < len(arrays); idx++ {
		maxDist = max(
			int(math.Abs(float64(arrays[idx][len(arrays[idx]) - 1] - smallest))),
			int(math.Abs(float64(largest - arrays[idx][0]))),
			maxDist,
		)
		smallest = min(smallest, arrays[idx][0])
		largest = max(largest, arrays[idx][len(arrays[idx]) - 1])
	}
	return maxDist
}
