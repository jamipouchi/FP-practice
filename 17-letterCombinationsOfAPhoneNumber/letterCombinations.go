package lettercombinations

var buttons = [...]string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	return buildCombinations(digits)
}

func buildCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{""}
	}
	lastDig := int((digits[len(digits)-1]) - '0')
	leftDigs := digits[:len(digits)-1]
	curr := buildCombinations(leftDigs)
	next := []string{}
	for _, c := range buttons[lastDig] {
		for _, str := range curr {
			next = append(next, str+string(c))
		}
	}
	return next
}
