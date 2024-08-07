package main

import "strconv"

func evalRPN(tokens []string) int {
	if len(tokens) == 1{
		ans, _ := strconv.ParseInt(tokens[0], 10, 32)
		return int(ans)
	}

	stack := []string{}
	for _, token := range tokens {
		switch token {
		case "+", "-", "*", "/":
			stack = append(
				stack[:len(stack) - 2], 
				eval(stack[len(stack) - 2], stack[len(stack) - 1], token),
		)
		default:
			stack = append(stack, token)
		}
	}
    ans, _ :=  strconv.ParseInt(stack[0], 10, 32)
	return int(ans)
}

func eval(token1, token2, op string) string {
	val1, _ := strconv.ParseInt(token1, 10, 32)
	val2, _ := strconv.ParseInt(token2, 10, 32)
	switch op {
	case "+": return strconv.Itoa(int(val1) + int(val2))
	case "-": return strconv.Itoa(int(val1) - int(val2))
	case "*": return strconv.Itoa(int(val1) * int(val2))
	case "/": return strconv.Itoa(int(val1) / int(val2))
	default : return ""
	}
}