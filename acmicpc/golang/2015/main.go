package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)

	s := make([]int, n)
	m := make(map[int]int)

	m[0] += 1

	ans := 0

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &s[i])

		if i > 0 {
			s[i] = s[i] + s[i-1]
		}

		// 0을 맨 처음에 넣어도 되는 이유
		// s[i] == 5
		// k == 5
		// s[i] - k == 0
		ans += m[s[i]-k]
		m[s[i]] += 1

	}

	fmt.Println(ans)

}
