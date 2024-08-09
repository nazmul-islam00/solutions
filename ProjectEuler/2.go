package main

func evenFibonacci() int {
	sum := 0
	term1, term2 := 0, 1
	for term2 < 4000000 {
		term1, term2 = term2, term1 + term2
		if term2 % 2 == 0 {
			sum += term2
		}
	}
	return sum
}