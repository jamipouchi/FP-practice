package main

func lexicalOrder(n int) []int {
	result := make([]int, 0, n)

	curr := 1
	for range n {
		result = append(result, curr)
		if curr*10 <= n {
			curr *= 10
		} else {
			for curr%10 == 9 || curr+1 > n {
				curr /= 10
			}
			curr++
		}
	}
	return result
}
