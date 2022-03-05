package main

import (
	"fmt"
	"strconv"
)

func solution(numbers string) int {

	// 7 자리
	// primes := getPrimes(10000000)
	fmt.Println(numbers)
	numberList := getNumbers(0, "", numbers)
	fmt.Println(numberList)
	ans := 0

	return ans
}

func getNumbers(selected int, current string, numbers string) map[int]int {
	fmt.Println("func getNumbers(selected int, current string, numbers string) map[int]int {")
	fmt.Printf("selected: %v, current: %v, number: %v\n", selected, current, numbers)

	if selected == ((1 << len(numbers)) - 1) {
		fmt.Println("if selected&((1<<len(numbers))-1) != 0 {")
		// no error
		currentInt, _ := strconv.ParseInt(current, 10, 64)

		return map[int]int{int(currentInt): 0}
	}

	numberList := make(map[int]int)
	for i := 0; i < len(numbers); i++ {
		fmt.Println("for i := 0; i < len(numbers); i++ {")
		fmt.Printf("i: %v, 1 << i: %v\n", i, 1<<i)
		if !(selected&(1<<i) != 0) {
			selected = selected | (1 << i)
			fmt.Println("selected = selected | (1 << i)")
			fmt.Printf("selected: %v, string(numbers[i]): %v\n", selected, string(numbers[i]))

			m1 := getNumbers(selected, current+string(numbers[i]), numbers)
			fmt.Println("m1 := getNumbers(selected, current+string(numbers[i]), numbers)")
			fmt.Printf("m1: %v\n", m1)
			for key, value := range m1 {
				numberList[key] = value
			}
			m2 := getNumbers(selected, current+"", numbers)
			fmt.Println("m2 := getNumbers(selected, current+, numbers)")
			fmt.Printf("m2: %v\n", m1)
			for key, value := range m2 {
				numberList[key] = value
			}
			selected = selected & (((1 << len(numbers)) - 1) - (1 << i))
		} else {
			fmt.Println("else")
			fmt.Println(selected)

		}
	}

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
