
func solution(n int, a []int) []int {
	b := make([]int, n)

	for i := 0; i < n; i++ {
		sum := 0
		cadidatedIndexes := []int{i - 1, i, i + 1}
		for _, cadidatedIndex := range cadidatedIndexes {
			if cadidatedIndex >= 0 && cadidatedIndex <= n-1 {
				sum += a[cadidatedIndex]
			}
		}
		b[i] = sum
	}
	return b
}