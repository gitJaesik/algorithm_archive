package main

import "fmt"

func solution(inputString string) bool {

	stringSize := len(inputString)

	ret := true
	for i := 0; i < stringSize/2; i++ {
		if inputString[i] != inputString[stringSize-1-i] {
			ret = false
			break
		}
	}
	return ret
}

func main() {
	// ret := solution("hello")
	// fmt.Println(ret)
	fmt.Println(solution("hello"))
	fmt.Println(solution("abba"))
	fmt.Println(solution("aba"))
}
