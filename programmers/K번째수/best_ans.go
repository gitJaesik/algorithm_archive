package main

import "sort"

func solution(array []int, commands [][]int) []int {
	var ret []int
	for _, cmd := range commands {
		slice := append([]int{}, array[cmd[0]-1:cmd[1]]...)
		sort.Ints(slice)
		ret = append(ret, slice[cmd[2]-1])
	}
	return ret
}
