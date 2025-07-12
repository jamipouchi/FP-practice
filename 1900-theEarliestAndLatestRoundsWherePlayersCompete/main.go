package main

import (
	"slices"
)

func isSolution(positions []int, firstPlayer, secondPlayer int) bool {
	for i := 0; i < len(positions)/2; i++ {
		if positions[i] == firstPlayer && positions[len(positions)-i-1] == secondPlayer {
			return true
		}
	}
	return false
}

func generatePositions(positions []int, firstPlayer, secondPlayer int) [][]int {
	if len(positions) <= 1 {
		return [][]int{positions}
	}
	nextPositions := [][]int{}
	left := positions[0]
	right := positions[len(positions)-1]
	middle := generatePositions(positions[1:len(positions)-1], firstPlayer, secondPlayer)
	if left == firstPlayer || left == secondPlayer {
		for _, ps := range middle {
			nextPositions = append(nextPositions, slices.Concat([]int{left}, ps))
		}
	} else if right == firstPlayer || right == secondPlayer {
		for _, ps := range middle {
			nextPositions = append(nextPositions, slices.Concat(ps, []int{right}))
		}
	} else {
		for _, ps := range middle {
			nextPositions = append(nextPositions, slices.Concat([]int{left}, ps))
			nextPositions = append(nextPositions, slices.Concat(ps, []int{right}))
		}
	}
	return nextPositions
}

func step(i int, positions []int, firstPlayer, secondPlayer int) []int {
	if isSolution(positions, firstPlayer, secondPlayer) {
		return []int{i}
	}
	nextPositions := generatePositions(positions, firstPlayer, secondPlayer)
	sols := []int{}
	for _, nextPosition := range nextPositions {
		next := step(i+1, nextPosition, firstPlayer, secondPlayer)
		sols = append(sols, next...)
	}
	return sols
}

func earliestAndLatest(n int, firstPlayer int, secondPlayer int) []int {
	positions := make([]int, n)
	for i := range n {
		positions[i] = i + 1
	}
	allSolutions := step(1, positions, firstPlayer, secondPlayer)
	min := slices.Min(allSolutions)
	max := slices.Max(allSolutions)
	return []int{min, max}
}
