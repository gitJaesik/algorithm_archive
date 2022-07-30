package main

import "fmt"

func pick(n int, picked []int, toPick int) {

	if toPick == 0 {
		fmt.Println(picked)
		return
	}

	// smallest := len(picked) == 0 ? 0 : len(picked) + 1

	smallest := 0
	if len(picked) > 0 {
		smallest = picked[len(picked)-1] + 1
	}

	for next := smallest; next < n; next++ {
		picked = append(picked, next)
		pick(n, picked, toPick-1)
		picked = picked[:len(picked)-1]
	}

}

func main() {

	pick(5, []int{}, 3)

}
