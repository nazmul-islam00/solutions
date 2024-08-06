package main

func kthDistinct(arr []string, k int) string {
	strings := map[string]bool{}
	for _, str := range arr {
		if _, ok := strings[str]; ok {
			strings[str] = false
		} else {
			strings[str] = true
		}
	}
	count := 0
	for _, str := range arr {
		if strings[str] {
			count++
			if count == k {
				return str
			}
		}
	}
	return ""
}