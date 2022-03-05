package main

import (
	"fmt"
	"strconv"
)

func solution(numbers string) int {

	// 7 자리
	primes := getPrimes(10000000)
	numberList := getNumbers(0, "", numbers)
	ans := 0

	for key, _ := range numberList {
		if primes[key] {
			ans += 1
		}
	}

	return ans
}

func getNumbers(selected int, current string, numbers string) map[int]int {

	if selected == ((1 << len(numbers)) - 1) {
		// no error
		currentInt, _ := strconv.ParseInt(current, 10, 64)

		return map[int]int{int(currentInt): 0}
	}

	numberList := make(map[int]int)
	for i := 0; i < len(numbers); i++ {
		if !(selected&(1<<i) != 0) {
			selected = selected | (1 << i)

			m1 := getNumbers(selected, current+string(numbers[i]), numbers)
			for key, value := range m1 {
				numberList[key] = value
			}
			m2 := getNumbers(selected, current+"", numbers)
			for key, value := range m2 {
				numberList[key] = value
			}
			selected = selected & (((1 << len(numbers)) - 1) - (1 << i))
		}
	}

	return numberList
}

func getNumbers2() {

}

/*
Perm([]rune("abc"), func(a []rune) {
	fmt.Println(string(a))
})
*/

// Perm calls f with each permutation of a.
func Perm(a []rune, f func([]rune)) {
	perm(a, f, 0)
}

// Permute the values at index i to len(a)-1.
func perm(a []rune, f func([]rune), i int) {
	if i > len(a) {
		f(a)
		return
	}
	perm(a, f, i+1)
	for j := i + 1; j < len(a); j++ {
		a[i], a[j] = a[j], a[i]
		perm(a, f, i+1)
		a[i], a[j] = a[j], a[i]
	}
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
