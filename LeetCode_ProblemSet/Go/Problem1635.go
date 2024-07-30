package main

func minimumDeletions(s string) int {
	cost := 0
	count_b := 0

	for _, ch := range s {
		if ch == 'b' {
			count_b++
		} else {
			cost = min(cost + 1, count_b)
		}
	}

	return cost
}