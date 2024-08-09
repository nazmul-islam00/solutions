package main

import (
	"math"
	"sort"
)

func largestPrimeFactor() int {
	num := 600851475143
	factors := getFactors(num)
	sort.SliceStable(factors, func(i, j int) bool {
		return factors[i] > factors[j]
	})
	for _, factor := range factors {
		if isPrime(factor) {
			return factor
		}
	}
	return -1
}

func getFactors(num int) []int {
	factors := []int{}
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num%i == 0 {
			factors = append(factors, i, num/i)
		}
	}
	return factors
}

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	if num%2 == 0 {
		return false
	}
	for i := 3; i <= int(math.Sqrt(float64(num))); i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}
