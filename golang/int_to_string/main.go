package main

import (
	"fmt"
	"strconv"
)

func main() {

	number := 20
	fmt.Println(number)
	fmt.Printf("%T\n", number)
	stringNumber := strconv.Itoa(number)
	fmt.Println(stringNumber)
	fmt.Printf("%T\n", stringNumber)

}
