package main

import (
	"fmt"
	"regexp"
)

func main() {
	var s string
	fmt.Scan(&s)
	// 	r := regexp.MustCompile("c[=-]|dz=|d-|lj|nj|[sz]=")
	r := regexp.MustCompile("c=|c-|dz=|d-|lj|nj|s=|z=").ReplaceAllString(s, ".")
	fmt.Print(len(r))
}
