package main

import "fmt"

func solution(participants []string, completion []string) string {
	players := make(map[string]int)

	for _, participant := range participants {
		if _, exist := players[participant]; exist {
			players[participant] += 1
		} else {
			players[participant] = 1
		}
	}

	for _, completio := range completion {
		if val, exist := players[completio]; exist {
			if val == 1 {
				delete(players, completio)
			} else {
				players[completio] -= 1
			}

		}
	}

	var ans string
	for val, _ := range players {
		ans = val
	}

	return ans
}

func main() {

	a1 := []string{"leo", "kiki", "eden"}
	b1 := []string{"eden", "kiki"}
	fmt.Println(solution(a1, b1))

	a3 := []string{"mislav", "stanko", "mislav", "ana"}
	b3 := []string{"stanko", "ana", "mislav"}
	fmt.Println(solution(a3, b3))
}
