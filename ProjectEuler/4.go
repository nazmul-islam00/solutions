package main

import (
	"sort"
	"strconv"
)

func largetPalindromeProduct() int {
	palindromes := []int{}
	for i := 999; i > 99; i--  {
		for j := 999; j > 99; j-- {
			if isPalindrome(i * j) {
				palindromes = append(palindromes, i * j)
			}
		}
	}
	sort.SliceStable(palindromes, func(i, j int) bool {
		return palindromes[i] > palindromes[j]
	})
	return palindromes[0]
}

func isPalindrome(num int) bool {
	str := strconv.Itoa(num)
	for i := 0; i < int(len(str) / 2); i++ {
		if str[i] != str[len(str) - 1 - i] {
			return false
		}
	}
	return true
}