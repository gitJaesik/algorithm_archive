package main

import (
	"fmt"
	"sort"
)

func solution(answers []int) []int {
	a := 0
	b := 0
	c := 0
	for i, answer := range answers {
		if getAAnswer(i) == answer {
			a += 1
		}
		if getBAnswer(i) == answer {
			b += 1
		}
		if getCAnswer(i) == answer {
			c += 1
		}
	}

	// m := map[int]int{1: a, 2: b, 3: c}
	students := []struct {
		Name  int
		Score int
	}{
		{1, a},
		{2, b},
		{3, c},
	}
	fmt.Println(students)

	sort.SliceStable(students, func(i int, j int) bool {
		if students[i].Score == students[j].Score {
			return students[i].Name < students[j].Name
		} else {
			return students[i].Score > students[j].Score
		}
	})

	fmt.Println(students)

	maxVal := students[0].Score
	var ans []int
	for _, student := range students {
		if student.Score == maxVal {
			ans = append(ans, student.Name)
		}
	}

	return ans
}

// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
func getAAnswer(index int) int {

	return (index % 5) + 1
}

// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
func getBAnswer(index int) int {
	ans := 2
	if index%2 == 0 {
		return ans
	}

	evenIdx := (index + 1) / 2
	if evenIdx%4 == 1 {
		return 1
	} else if evenIdx%4 == 2 {
		return 3
	} else if evenIdx%4 == 3 {
		return 4
	}

	// } else if evenIdx%4 == 0 {
	return 5
}

// 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
func getCAnswer(index int) int {
	evenIdx := index / 2

	if evenIdx%5 == 0 {
		return 3
	} else if evenIdx%5 == 1 {
		return 1
	} else if evenIdx%5 == 2 {
		return 2
	} else if evenIdx%5 == 3 {
		return 4
	}
	// } else if evenIdx%5 == 4 {
	return 5
}

/*
1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
*/

/*
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
*/

func main() {
	a1 := []int{1, 2, 3, 4, 5}
	fmt.Println(solution(a1))

	a2 := []int{1, 3, 2, 4, 2}
	fmt.Println(solution(a2))
}
