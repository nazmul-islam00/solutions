package main

import "sort"

func rangeSum(nums []int, n int, left int, right int) int {
	prefixSums := getPrefixSum(nums, n)
	subarraySums := getSubarraySums(prefixSums, n)
	return getSortedSumOverRange(subarraySums, left, right)
}

func getPrefixSum(nums []int, n int) []int {
	prefixSums := make([]int, n+1)
	prefixSum := 0
	for i := range n {
		prefixSum += nums[i]
		prefixSums[i+1] = prefixSum
	}
	return prefixSums
}

func getSubarraySums(prefixSums []int, n int) []int {
	subarraySums := make([]int, (n*(n+1))/2)
	idx := 0
	for i := range n {
		for j := i; j < n; j++ {
			subarraySums[idx] = prefixSums[j+1] - prefixSums[i]
			idx++
		}
	}
	return subarraySums
}

func getSortedSumOverRange(subarraySums []int, left, right int) int {
	sort.Slice(subarraySums, func(i, j int) bool {
		return subarraySums[i] < subarraySums[j]
	})
	sum := 0
	for i := left -1; i < right; i++ {
		sum = (sum + subarraySums[i]) % (1e9 + 7)
	}
	return sum
}