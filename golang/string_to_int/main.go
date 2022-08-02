package main

import (
	"fmt"
	"strconv"
)

func main() {
	s := "0123"

	i, _ := strconv.Atoi(s)
	fmt.Println(i)

}
