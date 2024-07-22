package main

import (
	"slices"
)

type NameHeight struct {
	Name   string
	Height int
}

func sortPeople(names []string, heights []int) []string {
	namesWithHeights := make([]NameHeight, len(names))
	for i, name := range names {
		namesWithHeights[i] = NameHeight{name, heights[i]}
	}
	slices.SortFunc(namesWithHeights, func(a, b NameHeight) int {
		return b.Height - a.Height
	})
	sortedNames := make([]string, len(names))
	for i, nameHeight := range namesWithHeights {
		sortedNames[i] = nameHeight.Name
	}
	return sortedNames
}
