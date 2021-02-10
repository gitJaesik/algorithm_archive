package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func solution(S string, C []int) int {
	ans := 0

	prevChar := S[0]
	prevCost := C[0]
	for i := 1; i < len(S); i++ {
		if S[i] == prevChar {
			ans += min(C[i], prevCost)
			// equal
			// prevChar = prevChar

			// prevCost
			prevCost = max(C[i], prevCost)
		} else {
			prevChar = S[i]
			prevCost = C[i]
		}
	}

	return ans
}

func main() {
	S := "abccdb"
	fmt.Println(S)

	var C []int
	C = append(C, 0, 1, 2, 3, 4, 5)
	fmt.Println(C)

	fmt.Println(solution(S, C))
}
