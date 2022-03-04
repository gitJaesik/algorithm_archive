func solution(n int, computers [][]int) int {
	cnt := 0
	visited := make([]bool, n)

	for i := 0; i < n; i++ {
		if visited[i] == false {
			dfs(n, computers, i, visited)
			cnt++
		}
	}
	return cnt
}

func dfs(n int, computers [][]int, now int, visited []bool) {
	visited[now] = true

	for i := 0; i < n; i++ {
		if computers[now][i] == 1 && visited[i] == false && now != i {
			visited[i] = true
			dfs(n, computers, i, visited)
		}
	}
}