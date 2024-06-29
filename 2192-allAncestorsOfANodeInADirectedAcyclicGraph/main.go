package main

import "slices"

func getAncestors(n int, edges [][]int) [][]int {
	// First we topo sort the graph
	topologicalOrder := []int{}
	inDegree := make([]int, n)
	graph := make([][]int, n)
	for _, edge := range edges {
		from, to := edge[0], edge[1]
		graph[from] = append(graph[from], to)
		inDegree[to]++
	}
	queue := []int{}
	for i := 0; i < n; i++ {
		if inDegree[i] == 0 {
			queue = append(queue, i)
		}
	}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		topologicalOrder = append(topologicalOrder, node)
		for _, neighbor := range graph[node] {
			inDegree[neighbor]--
			if inDegree[neighbor] == 0 {
				queue = append(queue, neighbor)
			}
		}
	}
	ancestorsSet := make([]map[int]bool, n)
	for i := 0; i < n; i++ {
		ancestorsSet[i] = map[int]bool{}
	}
	for _, node := range topologicalOrder {
		for _, neighbor := range graph[node] {
			for ancestor := range ancestorsSet[node] {
				ancestorsSet[neighbor][ancestor] = true
			}
			ancestorsSet[neighbor][node] = true
		}
	}
	ancestors := make([][]int, n)
	for i := 0; i < n; i++ {
		ancestors[i] = []int{}
		for ancestor := range ancestorsSet[i] {
			ancestors[i] = append(ancestors[i], ancestor)
		}
		slices.Sort(ancestors[i])
	}
	return ancestors
}
