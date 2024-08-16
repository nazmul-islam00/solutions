package main

import (
	"math"
	"sort"
)

func maxDistance(arrays [][]int) int {
	_max_min := make([][]int, len(arrays))
	_max := make([][]int, len(arrays))
	_min := make([][]int, len(arrays))

	for idx, array := range arrays {
		_max_min[idx] = get_max_min(array)
	}
	for idx, array := range _max_min {
		_max[idx] = []int{array[0], idx}
		_min[idx] = []int{array[1], idx}
	}

	sort.SliceStable(_max, func(i, j int) bool {
		return _max[i][0] > _max[j][0]
	})
	sort.SliceStable(_min, func(i, j int) bool {
		return _min[i][0] < _min[j][0]
	})

	if _max[0][1] != _min[0][1] {
		return _max[0][0] - _min[0][0]
	}
	return max(
		int(math.Abs(float64(_max[0][0] - _min[1][0]))),
		int(math.Abs(float64(_max[1][0] - _min[0][0]))),
	)
}

func get_max_min(array []int) []int {
	_max, _min := array[0], array[0]
	for _, num := range array {
		_max = max(_max, num)
		_min = min(_min, num)
	}
	return []int{_max, _min}
}