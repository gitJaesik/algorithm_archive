package main

import "fmt"

func checkAll(idx int, sum int, numbers []int, ans int) int {
	if idx == len(numbers) {
		if sum == ans {
			return 1
		} else {
			return 0
		}
	}

	ret := 0
	ret += checkAll(idx+1, sum+numbers[idx], numbers, ans)
	ret += checkAll(idx+1, sum-numbers[idx], numbers, ans)

	return ret
}

func solution(numbers []int, target int) int {

	ans := checkAll(0, 0, numbers, target)

	return ans
}

/*
[1, 1, 1, 1, 1]		3	5
[4, 1, 2, 1]		4	2
*/
func main() {
	n1 := []int{1, 1, 1, 1, 1}
	t1 := 3
	fmt.Println(solution(n1, t1))

	n2 := []int{4, 1, 2, 1}
	t2 := 4
	fmt.Println(solution(n2, t2))
}
