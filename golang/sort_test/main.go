package main

import (
	"fmt"
	"sort"
)

func main() {
	a := []int{1, 3, 2, 6, 4, 7, 8, 10}

	fmt.Println(a)

	sort.Ints(a)

	fmt.Println(a)
}
