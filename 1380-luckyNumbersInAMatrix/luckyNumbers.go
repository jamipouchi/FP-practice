package main

func luckyNumbers(matrix [][]int) []int {
	var res []int
	for i := 0; i < len(matrix); i++ {
		min := matrix[i][0]
		minIndex := 0
		for j := 1; j < len(matrix[i]); j++ {
			if matrix[i][j] < min {
				min = matrix[i][j]
				minIndex = j
			}
		}
		isMax := true
		for k := 0; k < len(matrix); k++ {
			if matrix[k][minIndex] > min {
				isMax = false
				break
			}
		}
		if isMax {
			res = append(res, min)
		}
	}
	return res
}
