package main

import "fmt"

func ReverseSliceAll(L []int) {
	N := len(L)
	Half := len(L) / 2
	for i := 0; i < Half; i++ {
		L[i], L[N-i] = L[N-i], L[i]
	}
}

// 1, 2
// 1, 2, 3, 4,
// N = 2 - 1 + 1 = 2
// Half = 2 / 2 = 1
// for i := 1; i < 1 + 1; i++ {
//
// }

func ReverseSlice(L []int, start, end int) {
	// fmt.Printf("start: %d, end: %d\n", start, end)
	N := end - start + 1
	Half := N / 2
	for i := start; i < start+Half; i++ {
		L[i], L[end-i] = L[end-i], L[i]
	}
}

func main() {
	var T int
	fmt.Scanf("%d", &T)
	// fmt.Println(T)
	for i := 0; i < T; i++ {
		var N int
		fmt.Scanf("%d", &N)
		L := make([]int, N)
		for j := 0; j < N; j++ {
			var Lj int
			fmt.Scanf("%d", &Lj)
			L[j] = Lj
		}

		// implement ReverseSort
		// j - i + 1
		ans := 0
		for k := 0; k < N-1; k++ {
			minVal := N
			minIndex := k
			for p := k; p < N; p++ {
				if minVal > L[p] {
					minVal = L[p]
					minIndex = p
				}
			}
			ans = ans + minIndex - k + 1
			ReverseSlice(L, k, minIndex)
			// min := int.min()
		}
		// fmt.Println(ans)
		fmt.Printf("Case # %d: %d\n", i+1, ans)

		// fmt.Println(N)
		// fmt.Println(L)
	}
}

/*
1
18
10 3 6 8 7 1 5 4 2 9 11 12 14 13 15 16 17 18

39
*/
