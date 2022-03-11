package main

import (
	"fmt"
	"sort"
	"strconv"
)

func solution(numbers []int) string {
	// sort
	// 큰 숫자 우선
	// 비교
	// - 길이가 짧은 숫자로 자르기, 크기가 큰 것 리턴, 같으면 다음 단계
	// - 둘을 합쳐서 더 큰 것을 리턴

	var bns BNS

	for _, num := range numbers {
		numStr := strconv.Itoa(num)
		bns = append(bns, BiggerNumber{num: numStr})
	}

	fmt.Println(bns)
	sort.Sort(bns)
	fmt.Println(bns)

	ans := ""
	for _, bn := range bns {
		ans += bn.num
	}

	if string(ans[0]) == "0" {
		return "0"
	}

	return ans
}

type BiggerNumber struct {
	num string
}

// ByAge implements sort.Interface for []Person based on
// the Age field.
type BNS []BiggerNumber

func (b BNS) Len() int      { return len(b) }
func (b BNS) Swap(i, j int) { b[i], b[j] = b[j], b[i] }
func (b BNS) Less(i, j int) bool {

	// left := b[i].num
	// left = left + left + left
	// right := b[j].num
	// right = right + right + right

	// if left > right {
	// 	return true
	// }
	// return false

	leftBNStr := b[i]
	rightBNStr := b[j]
	// equal
	leftRightInt, _ := strconv.ParseInt(leftBNStr.num+rightBNStr.num, 10, 64)
	rightLeftInt, _ := strconv.ParseInt(rightBNStr.num+leftBNStr.num, 10, 64)

	if leftRightInt > rightLeftInt {
		return true
	} else {
		return false
	}

}

/*
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"
*/
func main() {
	numbers1 := []int{6, 10, 2}
	fmt.Println(solution(numbers1))
	numbers2 := []int{3, 30, 34, 5, 9}
	fmt.Println(solution(numbers2))
	numbers3 := []int{0, 0, 0, 0}
	fmt.Println(solution(numbers3))

}
