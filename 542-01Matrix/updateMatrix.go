// This solution was my original thought, I think it's much cleaner than the multi-bfs approach.
// Implementing it is dull though, (lot of checking idx are right), and it is inspired by another solution.
func updateMatrix(mat [][]int) [][]int {

	n := len(mat)
	m := len(mat[0])

	if mat[0][0] != 0 {
		mat[0][0] = m + n
	}

	// top-left -> bottom-right
	for j := 1; j < m; j++ {
		if mat[0][j] != 0 {
			mat[0][j] = mat[0][j-1] + 1
		}
	}
	for i := 1; i < n; i++ {
		if mat[i][0] != 0 {
			mat[i][0] = mat[i-1][0] + 1
		}
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if mat[i][j] != 0 {
				mat[i][j] = min(mat[i][j-1], mat[i-1][j]) + 1
			}
		}
	}

	// bottom-right -> top-left
	for j := m - 2; j >= 0; j-- {
		if mat[n-1][j] != 0 {
			mat[n-1][j] = min(mat[n-1][j], mat[n-1][j+1]+1)
		}
	}
	for i := n - 2; i >= 0; i-- {
		if mat[i][m-1] != 0 {
			mat[i][m-1] = min(mat[i][m-1], mat[i+1][m+1]+1)
		}
	}
	for i := n - 2; i >= 0; i-- {
		for j := m - 2; j >= 0; j-- {
			if mat[i][j] != 0 {
				mat[i][j] = min(mat[i][j], mat[i+1][j]+1, mat[i][j+1]+1)
			}
		}
	}
	return mat
}

// min, as leetcode still hasn't updated to go 1.21 zzz
func min(nums ...int) int {
	min := nums[0]
	for _, num := range nums[1:] {
		if num < min {
			min = num
		}
	}
	return min
}
