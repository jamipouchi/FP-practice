package isinterleave

var imposs [][]bool

func isInterleave(s1, s2, s3 string) bool {
	if len(s1) + len(s2) != len(s3) {
		return false
	}
	imposs = make([][]bool, len(s1) + 1)
	for i := 0; i <= len(s1); i++ {
		imposs[i] = make([]bool, len(s2) + 1)
	}
	return isInterleaveFrom(s1, s2, s3, 0, 0, 0)
}

func isInterleaveFrom(s1, s2, s3 string, p1, p2, p3 int) bool {
	if p3 == len(s3) {
		return true
	}
	if imposs[p1][p2] {
		return false
	}
	if (p1 < len(s1) && s1[p1] != s3[p3]) && (p2 < len(s2) && s2[p2] != s3[p3]) {
		imposs[p1][p2] = true
		return false
	}
	if p1 < len(s1) && s1[p1] == s3[p3] {
		if isInterleaveFrom(s1, s2, s3, p1+1, p2, p3+1) {
			return true
		}
	}
	if p2 < len(s2) && s2[p2] == s3[p3] {
		if isInterleaveFrom(s1, s2, s3, p1, p2+1, p3+1) {
			return true
		}
	}
	imposs[p1][p2] = true
	return false
}
