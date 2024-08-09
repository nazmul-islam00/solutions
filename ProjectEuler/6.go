package main

import (
	"math"
)

func sumSquareDifference() int {
	n := 100
	sumOfSquares := n * (n + 1) * (2 * n + 1) / 6
	squareOfSum := int(math.Pow(float64(n * (n + 1) / 2), 2))
	return int(math.Abs(float64(sumOfSquares - squareOfSum)))
}