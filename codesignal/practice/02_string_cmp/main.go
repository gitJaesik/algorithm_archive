package main

import "fmt"

func solution(s string) int {
	// declare ans
	ans := 0

	// for loop to select a
	for aEnd := 1; aEnd < len(s)-1; aEnd++ {
		// fmt.Printf("aEnd : %d\n", aEnd)

		a := s[:aEnd]

		for bEnd := aEnd + 1; bEnd < len(s); bEnd++ {
			// fmt.Printf("bEnd : %d\n", bEnd)

			b := s[aEnd:bEnd]
			c := s[bEnd:]

			if a+b != b+c && a+b != c+a {
				// fmt.Println(a + b)
				// fmt.Println(b + c)
				// fmt.Println(c + a)

				ans += 1
			}
		}

	}
	return ans
}

func main() {

	q1 := "abc"
	fmt.Println(solution(q1))
	q2 := "abca"
	fmt.Println(solution(q2))
	q3 := "abcab"
	fmt.Println(solution(q3))
	q4 := "abcabc"
	fmt.Println(solution(q4))
}
