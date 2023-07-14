package longestarithmeticsubsequenceofgivendifference

func longestSubsequence(arr []int, difference int) int {
	nextNumbers := make(map[int]int)

	largestSubsequence := 0
	for _, num := range arr {
		nextCount := nextNumbers[num] + 1 // 0 if it didn't exist -- thank you golang!
		delete(nextNumbers, num)
		nextNumbers[num+difference] = max(nextNumbers[num+difference], nextCount)
		largestSubsequence = max(largestSubsequence, nextCount)
	}
	return largestSubsequence
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
