package minextrachar

import (
	"strings"
)

var memo []int

func minExtraChar(s string, dictionary []string) int {
	memo = make([]int, len(s)+1)
	for i := range memo {
		memo[i] = -1
	}
	memo[0] = 0
	return minExtraCharRec(s, dictionary)
}

func minExtraCharRec(s string, dict []string) int {
	if memo[len(s)] != -1 {
		return memo[len(s)]
	}
	// try with prefixes
	ls := []int{}
	for _, w := range dict {
		if strings.HasPrefix(s, w) {
			if len(s) == len(w) {
				memo[len(s)] = 0
				return 0
			}
			ls = append(ls, minExtraCharRec(s[len(w):], dict))
		}
	}
	// try skipping the letter if best prefix is not found
	ls = append(ls, 1+minExtraCharRec(s[1:], dict))
	memo[len(s)] = min(ls...)
	return memo[len(s)]
}

func min(nums ...int) int {
	min := nums[0]
	for _, num := range nums[1:] {
		if num < min {
			min = num
		}
	}
	return min
}
