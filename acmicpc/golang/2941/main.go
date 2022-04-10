// 크로아티아 알파벳
package main

import "fmt"

func Solution(s string) int {
	croatia := []string{"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}

	ans := 0
	for i := 0; i < len(s); {
		// fmt.Printf("i is %d\n", i)
		hasCroatia := false
		for _, word := range croatia {
			// fmt.Printf("word is %s\n", word)
			// fmt.Printf("s[i:i+len(word)] is %s\n", s[i:i+len(word)])

			if i+len(word) <= len(s) && s[i:i+len(word)] == word {
				ans += 1
				i += len(word)
				hasCroatia = true
				break
			}
		}
		if hasCroatia {
			continue
		}
		ans += 1
		i += 1
	}

	return ans
}

func main() {
	// fmt.Println("hello 2941")
	// var a, b int
	// fmt.Scanf("%d %d", &a, &b)

	var s string
	fmt.Scanf("%s", &s)
	fmt.Println(Solution(s))
	// fmt.Println(s)
}
