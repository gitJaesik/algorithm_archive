package main

import (
	"container/heap"
	"fmt"
	"strconv"
	"strings"
)

/*
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]
// h := &IntHeap{2, 1, 5}
// heap.Init(h)
// heap.Push(h, 3)
// fmt.Printf("minimum: %d\n", (*h)[0])
// for h.Len() > 0 {
// 	fmt.Printf("%d \n", heap.Pop(h))
// }
*/
func solution(operations []string) []int {

	hmin := &IntHeap{}
	heap.Init(hmin)
	hmax := &IntHeapRev{}
	heap.Init(hmax)
	h := make(map[int]int)

	for _, operation := range operations {
		commands := strings.Split(operation, " ")
		fmt.Printf("commands[0]: %v, commands[1]: %v \n", commands[0], commands[1])
		if commands[0] == "I" {
			strToInt, _ := strconv.ParseInt(commands[1], 10, 64)
			heap.Push(hmin, int(strToInt))
			heap.Push(hmax, int(strToInt))
			if _, exist := h[int(strToInt)]; exist {
				h[int(strToInt)] += 1
			} else {
				h[int(strToInt)] = 1
			}
			// fmt.Printf("I %v\n", commands[1])
		} else if commands[0] == "D" && len(h) > 0 {
			if commands[1] == "1" {
				maxVal := heap.Pop(hmax).(int)
				fmt.Printf("maxVal: %v\n", maxVal)
				h[maxVal] -= 1
				if val, _ := h[maxVal]; val == 0 {
					delete(h, maxVal)
				}
				hmin = &IntHeap{}
				for key, _ := range h {
					heap.Push(hmin, key)
				}

				// fmt.Println("D 1")
			} else if commands[1] == "-1" {
				minVal := heap.Pop(hmin).(int)
				fmt.Printf("minVal: %v\n", minVal)
				h[minVal] -= 1
				if val, _ := h[minVal]; val == 0 {
					delete(h, minVal)
				}
				hmax = &IntHeapRev{}
				for key, _ := range h {
					heap.Push(hmax, key)
				}
				// fmt.Println("D -1")
			}
		}
		fmt.Printf("h: %v\n", h)
		fmt.Printf("hmin: %v\n", hmin)
		fmt.Printf("hmax: %v\n", hmax)
	}
	fmt.Println("final")
	fmt.Printf("h: %v\n", h)
	fmt.Printf("hmin: %v\n", hmin)
	fmt.Printf("hmax: %v\n", hmax)

	if len(h) == 0 {
		return []int{0, 0}
	}

	return []int{heap.Pop(hmax).(int), heap.Pop(hmin).(int)}
}

// An IntHeap is a min-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type IntHeapRev []int

func (h IntHeapRev) Len() int           { return len(h) }
func (h IntHeapRev) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeapRev) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeapRev) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeapRev) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

/*
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]
입력값 〉	["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
기댓값 〉	[333, -45]
*/
func main() {
	o1 := []string{"I 16", "D 1"}
	fmt.Println(solution(o1))
	o2 := []string{"I 7", "I 5", "I -5", "D -1"}
	fmt.Println(solution(o2))
	o3 := []string{"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"}
	fmt.Println(solution(o3))
}
