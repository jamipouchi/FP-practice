package generateparenthesis

func generateParenthesis(n int) []string {
	return generateParenthesisUpTo(n, 0, 0, "")
}

func generateParenthesisUpTo(numParenthesis, open, close int, curr string) []string {
	if open+close == 2*numParenthesis {
		return []string{curr}
	}
	parenthesis := []string{}
	if open < numParenthesis {
		parenthesis = append(parenthesis, generateParenthesisUpTo(numParenthesis, open+1, close, curr+"(")...)
	}
	if open > close {
		parenthesis = append(parenthesis, generateParenthesisUpTo(numParenthesis, open, close+1, curr+")")...)
	}
	return parenthesis
}
