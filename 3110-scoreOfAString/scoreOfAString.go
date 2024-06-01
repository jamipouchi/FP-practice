package main

func scoreOfString(s string) int {
	score := 0
	for i := 1; i < len(s); i++ {
		score += myAbs(int(s[i]) - int(s[i-1]))
	}
	return score
}

func myAbs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
