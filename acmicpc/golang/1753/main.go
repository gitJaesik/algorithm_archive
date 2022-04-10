// 최단경로
package main

import "fmt"

func main() {
	var V, E int
	var start int

	fmt.Scanf("%d, %d", &V, &E)
	fmt.Scanf("%d", &start)

	a := make(map[int][]int)

	for i := 0; i < E; i++ {
		var s, e, w int
		fmt.Scanf("%d %d %d", &s, &e, &w)
	}

}
