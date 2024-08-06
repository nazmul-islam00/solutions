package main

import "sort"

func minimumPushes(word string) int {
	count := map[rune]int{}
	for _, ch := range word {
		count[ch]++
	}

	keys := []rune{}
	for ch := range count {
		keys = append(keys, ch)
	}
	sort.SliceStable(keys, func(i, j int) bool {
		return count[keys[j]] < count[keys[i]]
	})

	cost := 0
	for idx, ch := range keys {
		if idx < 8 {
			cost += count[ch]
		} else if idx < 16 {
			cost += count[ch] * 2
		} else if idx < 24 {
			cost += count[ch] * 3
		} else {
			cost += count[ch] * 4
		}
	}
	return cost
}