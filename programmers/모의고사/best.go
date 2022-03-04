func solution(answers []int) (result []int) {
	idx, score := make([]int, 3), make([]int, 3)
	pattern := [][]int{{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}}
	for i := 0; i < len(answers); i++ {
		for j := 0; j < 3; j++ {
			idx[j] %= len(pattern[j])
			if answers[i] == pattern[j][idx[j]] {
				score[j]++
			}
			idx[j]++
		}
	}
	max := -1
	for i := 0; i < 3; i++ {
		if score[i] > max {
			result = []int{i + 1}
			max = score[i]
		} else if score[i] == max {
			result = append(result, i+1)
		}
	}
	return
}