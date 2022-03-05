package main

import (
	"fmt"
	"strconv"
)

func solution(numbers string) int {

	// 7 자리
	// primes := getPrimes(10000000)
	// numberList := getNumbers(numbers)
	ans := 0

	return ans
}

func getNumbers(idx int, numbers string, current string) map[int]int {
	if idx == len(numbers) {

		// no error
		currentInt, _ := strconv.ParseInt(current, 10, 64)

		return map[int]int{int(currentInt): 0}
	}

	var numberList map[int]int

	return numberList
}

func getPrimes(n int) []bool {

	// 10000000
	primes := make([]bool, n)
	for i, _ := range primes {
		primes[i] = true
	}

	primes[0] = false
	primes[1] = false

	for i := 2; i < n; i++ {
		if primes[i] {
			for j := i * i; j < n; j += i {
				primes[j] = false
			}
		}
	}

	return primes
}

/*
"17"	3
"011"	2
*/
func main() {
	n1 := "17"
	fmt.Println(solution(n1))
	n2 := "011"
	fmt.Println(solution(n2))
	return
}
