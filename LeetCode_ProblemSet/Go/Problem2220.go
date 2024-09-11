package main

import (
	"strconv"
	"strings"
)

func minBitFlips(start int, goal int) int {
    startBin, goalBin := strconv.FormatInt(int64(start), 2), strconv.FormatInt(int64(goal), 2)
	startLen, goalLen := len(startBin), len(goalBin)
	maxLen := max(startLen, goalLen)
	startBin = strings.Join([]string{
		strings.Repeat("0", maxLen - startLen), startBin, 
	}, "")
	goalBin = strings.Join([]string{
		strings.Repeat("0", maxLen - goalLen), goalBin, 
	}, "")
	count := 0
	for i := 0; i < maxLen; i++ {
		if startBin[i] != goalBin[i] {
			count++
		}
	}
	return count
}