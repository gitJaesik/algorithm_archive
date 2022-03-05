package main

import (
	"fmt"
	"sort"
)

func solution(array []int, commands [][]int) []int {
	var ans []int
	for _, command := range commands {
		arr := make([]int, command[1]-command[0]+1)
		copy(arr, array[command[0]-1:command[1]])
		// fmt.Printf("arr :%v\n", arr)
		sort.Ints(arr)
		// fmt.Printf("arr :%v\n", arr)
		// ans = append(ans, arr[command[2]]-1)
		// fmt.Printf("arr :%v\n", arr)
		// fmt.Printf("third :%v\n", command[2])
		// fmt.Printf("ans :%v\n", arr[command[2]-1])
		ans = append(ans, arr[command[2]-1])
	}

	return ans
}

func main() {

	// [1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
	array := []int{1, 5, 2, 6, 3, 7, 4}
	commands := [][]int{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}}
	// fmt.Printf("arr :%v\n", solution(array, commands))
	fmt.Printf("arr :%v\n", solution(array, commands))
	// solution(array, commands)
}
