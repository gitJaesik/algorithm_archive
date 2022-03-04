package main

import "fmt"

func solution(n int, computers [][]int) int {

	ds := makeOptimizedDisjointSet(n)

	for i, network := range computers {
		for j, isConnect := range network {
			// if isConnect == 1 && i != j {
			if isConnect == 1 {
				ds.union(i, j)
			}
		}
	}

	networks := make(map[int]int)

	for i := 0; i < n; i++ {
		networks[ds.find(i)] = 1
	}

	return len(networks)
}

// union and find
type OptimizedDisjointSet struct {
	parent []int
	rank   []int
}

func makeOptimizedDisjointSet(n int) OptimizedDisjointSet {
	ods := OptimizedDisjointSet{}

	ods.parent = make([]int, n)
	ods.rank = make([]int, n)
	for i := 0; i < n; i++ {
		ods.parent[i] = i
		ods.rank[i] = 1
	}

	return ods
}

func (ods *OptimizedDisjointSet) find(u int) int {
	if u == ods.parent[u] {
		return u
	}

	parentu := ods.find(ods.parent[u])
	ods.parent[u] = parentu
	return ods.parent[u]
}

func (ods *OptimizedDisjointSet) union(u int, v int) {
	uu := ods.find(u)
	vv := ods.find(v)

	if uu == vv {
		return
	}

	if ods.rank[uu] == ods.rank[vv] {
		ods.parent[uu] = vv
		ods.rank[vv] += 1
	} else if ods.rank[uu] < ods.rank[vv] {
		ods.parent[uu] = vv
	} else {
		ods.parent[vv] = uu
	}
}

/*
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1
*/

func main() {
	n1 := 3
	c1 := [][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}
	fmt.Println(solution(n1, c1))

	n2 := 3
	c2 := [][]int{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}
	fmt.Println(solution(n2, c2))
}
