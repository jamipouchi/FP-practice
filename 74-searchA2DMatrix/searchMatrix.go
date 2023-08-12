package searchmatrix

import "sort"

func searchMatrix(matrix [][]int, target int) bool {
	row := sort.Search(len(matrix), func(i int) bool { return matrix[i][0] >= target })

	if row == len(matrix) || matrix[row][0] != target {
		if row > 0 {
			row--
		} else {
			return false
		}
	} else {
		return true
	}

	col := sort.SearchInts(matrix[row], target)
	if col == len(matrix[row]) {
		return false
	} else {
		return matrix[row][col] == target
	}
}
