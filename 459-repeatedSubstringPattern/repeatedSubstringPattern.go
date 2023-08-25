package repeatedsubstringpattern

import "strings"

func repeatedSubstringPattern(s string) bool {
	for i := 1; i <= len(s)/2; i++ {
		if len(s)%i == 0 && check(s, i) {
			return true
		}
	}
	return false
}

func check(s string, i int) bool {
	return strings.Count(s, s[:i]) == len(s)/i
}
