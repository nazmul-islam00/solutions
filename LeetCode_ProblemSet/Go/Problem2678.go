package main

import "strconv"

func countSeniors(details []string) int {
	count := 0
	for _, detail := range details {
		if age, _ := strconv.Atoi(detail[11 : 13]); age > 60 {
			count++
		}
	}
	return count
}