package main

import "fmt"

func solution(phone_book []string) bool {
	phone_bpe := make(map[string]int)

	for _, phone_boo := range phone_book {

		var strs string
		for _, str := range phone_boo {
			strs += string(str)

			if _, exist := phone_bpe[strs]; exist {
				phone_bpe[strs] += 1
			} else {
				phone_bpe[strs] = 1
			}

		}
	}

	ans := true
	for _, phone_boo := range phone_book {
		if phone_bpe[phone_boo] > 1 {
			ans = false
			break
		}
	}

	return ans
}

func main() {

	a1 := []string{"119", "97674223", "1195524421"}
	fmt.Println(solution(a1))

	a2 := []string{"123", "456", "789"}
	fmt.Println(solution(a2))

	a3 := []string{"12", "123", "1235", "567", "88"}
	fmt.Println(solution(a3))
}
