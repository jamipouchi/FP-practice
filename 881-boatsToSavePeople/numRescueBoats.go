package main

import (
	"slices"
)

func numRescueBoats(people []int, limit int) int {
	slices.Sort(people)
	smallestIdx, biggestIdx := 0, len(people)-1
	totalBoats := 0
	for smallestIdx <= biggestIdx {
		if people[smallestIdx]+people[biggestIdx] <= limit {
			smallestIdx++
		}
		biggestIdx--
		totalBoats++
	}
	return totalBoats
}
