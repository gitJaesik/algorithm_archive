package main

import "fmt"

func pick(n int, picked []int, toPick int) [][]int {

	if toPick == 0 {
		// fmt.Println(picked)
		// return
		retd := [][]int{}
		retd = append(retd, picked)
		return retd
	}

	// smallest := len(picked) == 0 ? 0 : len(picked) + 1

	smallest := 0
	if len(picked) > 0 {
		smallest = picked[len(picked)-1] + 1
	}

	ret := [][]int{}

	for next := smallest; next < n; next++ {
		picked = append(picked, next)
		pickedRet := pick(n, picked, toPick-1)
		ret = append(ret, pickedRet...)
		picked = picked[:len(picked)-1]
	}

	return ret
}

func main() {

	ret := pick(5, []int{}, 3)
	fmt.Println(ret)

}
