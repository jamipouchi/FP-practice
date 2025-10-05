package main

import (
	"iter"
)

type Status bool

const (
	UNKNOWN Status = false // explicitily default value
	ALLOWED Status = true
)

type Position struct {
	row int
	col int
}

func (from Position) Neighbours(maxR, maxC int) iter.Seq[Position] {
	dirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	return func(yield func(Position) bool) {
		for _, dir := range dirs {
			newR := from.row + dir[0]
			newC := from.col + dir[1]
			if newR >= 0 && newR < maxR && newC >= 0 && newC < maxC {
				if !yield(Position{newR, newC}) {
					return
				}
			}
		}
	}
}

func pacificAtlantic(heights [][]int) [][]int {
	maxR := len(heights)
	maxC := len(heights[0])
	pacific := make([][]Status, maxR)
	atlantic := make([][]Status, maxR)
	for i := range maxR {
		pacific[i] = make([]Status, maxC)
		atlantic[i] = make([]Status, maxC)
	}
	pacificInitialPositions := make(map[Position]struct{})
	atlanticInitialPositions := make(map[Position]struct{})
	// first row can go to pacific
	for j := range pacific[0] {
		pacific[0][j] = ALLOWED
		pacificInitialPositions[Position{0, j}] = struct{}{}
	}
	// first column can go to pacific
	for i := range pacific {
		pacific[i][0] = ALLOWED
		pacificInitialPositions[Position{i, 0}] = struct{}{}
	}
	// last row can go to atlantic
	for j := range atlantic[len(atlantic)-1] {
		atlantic[len(atlantic)-1][j] = ALLOWED
		atlanticInitialPositions[Position{len(atlantic) - 1, j}] = struct{}{}
	}
	// last column can go to atlantic
	for i := range atlantic {
		atlantic[i][len(atlantic[0])-1] = ALLOWED
		atlanticInitialPositions[Position{i, len(atlantic[0]) - 1}] = struct{}{}
	}

	// create a set of positions
	fill(atlantic, atlanticInitialPositions, heights)
	fill(pacific, pacificInitialPositions, heights)
	result := [][]int{}
	for i := range heights {
		for j := range heights[0] {
			if pacific[i][j] == ALLOWED && atlantic[i][j] == ALLOWED {
				result = append(result, []int{i, j})
			}
		}
	}
	return result
}

func fill(status [][]Status, curr map[Position]struct{}, heights [][]int) {
	seen := make(map[Position]struct{})
	for len(curr) > 0 {
		newCurr := make(map[Position]struct{})
		for pos := range curr {
			for nextPos := range pos.Neighbours(len(status), len(status[0])) {
				if _, exists := seen[nextPos]; exists {
					continue
				}
				if status[nextPos.row][nextPos.col] == UNKNOWN && heights[nextPos.row][nextPos.col] >= heights[pos.row][pos.col] {
					status[nextPos.row][nextPos.col] = ALLOWED
					newCurr[nextPos] = struct{}{}
				}
			}
			seen[pos] = struct{}{}
		}
		curr = newCurr
	}
}
