package main

func removeChars(str *string, twoChars string) int {
	var removed int
	var stack []byte

	for i := 0; i < len(*str); i++ {
		stack = append(stack, (*str)[i])
		if len(stack) >= 2 && string(stack[len(stack)-2])+string(stack[len(stack)-1]) == twoChars {
			stack = stack[:len(stack)-2]
			removed++
		}
	}
	*str = string(stack)
	return removed
}

func maximumGain(s string, x int, y int) int {
	var removedAB int
	var removedBA int

	if x > y {
		removedAB = removeChars(&s, "ab")
		removedBA = removeChars(&s, "ba")
	} else {
		removedBA = removeChars(&s, "ba")
		removedAB = removeChars(&s, "ab")
	}
	return removedAB*x + removedBA*y
}
