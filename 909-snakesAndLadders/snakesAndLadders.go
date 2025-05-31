package main

import (
	"math"
)

func snakesAndLadders(board [][]int) int {
	n := len(board)
	distanceTo := make([]int, n*n+1)
	for i := range len(distanceTo) - 1 {
		distanceTo[i] = -1
	}
	distanceTo[n*n] = 0
	for i := n*n - 1; i >= 1; i-- {
		calculateDistanceTo(i, n, distanceTo, board)
	}
	if distanceTo[1] == math.MaxInt {
		return -1
	} else {
		return distanceTo[1]
	}
}

func calculateDistanceTo(i, n int, distanceTo []int, board [][]int) {
	if distanceTo[i] != -1 {
		return
	}
	minDistance := math.MaxInt - 1
	for j := i + 1; j <= min(i+6, n*n); j++ {
		row, col := getPosition(j, n)
		if board[row][col] == i {
			continue
		}
		k := j
		if board[row][col] != -1 {
			k = board[row][col]
		}
		if distanceTo[k] == -1 {
			calculateDistanceTo(k, n, distanceTo, board)
		}
		minDistance = min(minDistance, distanceTo[k])
	}
	distanceTo[i] = minDistance + 1
}

func getPosition(label int, n int) (row, col int) {
	row = n - 1 - ((label - 1) / n)
	col = (label - 1) % n
	if row%2 == n%2 {
		col = n - 1 - col
	}
	return row, col
}
