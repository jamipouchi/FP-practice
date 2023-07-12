package eventualSafeNodes

import (
	"sort"
)

func eventualSafeNodes(graph [][]int) []int {
	// If a node has no outgoing edges, then it is a safe node.
	// If a node points to a safe node, then it is a safe node.

	safeNodes := make(map[int]struct{})

	// 1. Add to safe nodes all nodes that have no outgoing edges
	for node, neighbors := range graph {
		if len(neighbors) == 0 {
			safeNodes[node] = struct{}{}
		}
	}
	// 2. While a node is only connected to safe nodes, it is a safe node
	change := true
	for change {
		change = false
	NextNode:
		for node, neighbors := range graph {
			if _, ok := safeNodes[node]; !ok {
				for _, neighbor := range neighbors {
					if _, ok := safeNodes[neighbor]; !ok {
						continue NextNode
					}
				}
				change = true
				safeNodes[node] = struct{}{}
			}
		}
	}
	keys := make([]int, len(safeNodes))

	i := 0
	for k := range safeNodes {
		keys[i] = k
		i++
	}
	sort.Ints(keys)
	return keys
}
