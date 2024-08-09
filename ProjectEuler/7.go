package main

func _10001stPrime() int {
	count := 1
	for i := 3; ; i += 2 {
		if isPrime(i) {
			count++
		}
		if count == 10001 {
			return i
		}
	}
}