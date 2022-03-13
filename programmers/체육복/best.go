package main

func solutionBest(n int, lost []int, reserve []int) int {
	for a := 0; a <= 1; a++ {
		for i := 0; i < len(reserve); i++ {
			for j := 0; j < len(lost); j++ {
				if reserve[i] == lost[j]+a || reserve[i] == lost[j]-a {
					reserve[i] = reserve[len(reserve)-1]
					reserve = reserve[:len(reserve)-1]
					lost[j] = lost[len(lost)-1]
					lost = lost[:len(lost)-1]
					i--
					j--
					break
				}
			}
		}
	}
	return n - len(lost)
}
