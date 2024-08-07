package main

func reverseWords(s string) string {
	words := getWords(s)
	ans := ""
	for idx := len(words) - 1; idx > -1; idx-- {
		if words[idx] != " " {
			ans += words[idx] + " "
		}
	}
	return ans[:len(ans) - 1]
}

func getWords(s string) []string {
	words := make([]string, 0, len(s))
	curWord := ""
	for _, ch := range s {
		if ch == ' ' && curWord != "" {
			words = append(words, curWord)
			curWord = ""
		} else if ch != ' ' {
			curWord += string(ch)
		}
	}
	if curWord != "" {
		words = append(words, curWord)
	}
	return words
}