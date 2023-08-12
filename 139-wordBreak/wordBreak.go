package wordbreak

import "strings"

var imposs []bool

func wordBreak(s string, wordDict []string) bool {
	imposs = make([]bool, len(s)+1)
	return check(s, wordDict)
}

func check(s string, wordDict []string) bool {
	if len(s) == 0 {
		return true
	}
	if imposs[len(s)] {
		return false
	}
	for _, word := range wordDict {
		if strings.HasSuffix(s, word) {
			if check(strings.TrimSuffix(s, word), wordDict) {
				return true
			}
		}
	}
	imposs[len(s)] = true
	return false
}
