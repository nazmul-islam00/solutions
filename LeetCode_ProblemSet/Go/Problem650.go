package main 

func minSteps(n int) int {
    count, cur := 0, 2
	for n > 1 {
		for n % cur == 0 {
			count += cur
			n /= cur
		}
		cur++
	}
	return count
}