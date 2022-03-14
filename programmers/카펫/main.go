package main

import "fmt"

func solution(brown int, yellow int) []int {

	// 노란색
	// 1, 1
	// 1, 2
	// 1, 3
	// 1, 4
	// 2, 1 -> x
	// 2, 2
	// 2, 3
	// 2, 4
	// 3, 1 -> x
	// 3, 2 -> x
	// 3, 3
	// 3, 4

	ans := make([]int, 0)

	for width := 1; width <= yellow; width++ {
		if yellow%width == 0 {
			height := yellow / width
			if height <= width {
				brown_width := width + 2
				brown_height := height + 2

				if brown == (brown_width*2)+(brown_height*2)-4 {
					ans = append(ans, brown_width, brown_height)
				}

			}
		}
	}

	return ans
}

/*
- - - -
- a a -
- - - -

brown은 한 줄
가로는 세로길이와 같거나 김

*/

/*
제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
*/
/*
brown	yellow	return
10		2		[4, 3]
8		1		[3, 3]
24		24		[8, 6]
*/
func main() {
	b1 := 10
	y1 := 2
	fmt.Println(solution(b1, y1))

	b2 := 8
	y2 := 1
	fmt.Println(solution(b2, y2))

	b3 := 24
	y3 := 24
	fmt.Println(solution(b3, y3))
}
