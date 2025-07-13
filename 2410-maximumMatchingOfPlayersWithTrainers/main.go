package main

import (
	"slices"
)

func matchPlayersAndTrainers(players []int, trainers []int) int {
	slices.Sort(players)
	slices.Sort(trainers)

	i, j := len(players)-1, len(trainers)-1
	for i >= 0 && j >= 0 {
		if players[i] <= trainers[j] {
			j--
		}
		i--
	}

	return len(trainers) - j - 1
}
