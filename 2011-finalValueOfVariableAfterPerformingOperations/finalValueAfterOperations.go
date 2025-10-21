package main

func finalValueAfterOperations(operations []string) int {
	result := 0
	for _, operation := range operations {
		if operation[1] == '+' {
			result++
		} else {
			result--
		}
	}
	return result
}
