package main

import (
	"container/heap"
)

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }
func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}
func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type PowerGrid struct {
	stations *IntHeap
	deleted  map[int]struct{}
}

func NewPowerGrid(station int) *PowerGrid {
	return &PowerGrid{
		stations: &IntHeap{station},
		deleted:  make(map[int]struct{}),
	}
}

func (pg *PowerGrid) AddStations(stations []int) {
	for _, station := range stations {
		heap.Push(pg.stations, station)
	}
}

func (pg *PowerGrid) CurrOrMin(station int) int {
	if _, deleted := pg.deleted[station]; !deleted {
		return station
	}
	for pg.stations.Len() > 0 {
		min := (*pg.stations)[0]
		if _, deleted := pg.deleted[min]; deleted {
			heap.Pop(pg.stations)
		} else {
			return min
		}
	}
	return -1
}

func (pg *PowerGrid) Delete(station int) {
	pg.deleted[station] = struct{}{}
}

type UnionFind struct {
	parent []int
}

func NewUnionFind(size int) *UnionFind {
	uf := &UnionFind{
		parent: make([]int, size+1),
	}
	for i := range size + 1 {
		uf.parent[i] = i
	}
	return uf
}

func (uf *UnionFind) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x])
	}
	return uf.parent[x]
}

func (uf *UnionFind) Union(x, y int) {
	rootX := uf.Find(x)
	rootY := uf.Find(y)
	if rootX != rootY {
		uf.parent[rootY] = rootX
	}
}

func processQueries(c int, connections [][]int, queries [][]int) []int {
	unionFind := NewUnionFind(c)
	for _, connection := range connections {
		unionFind.Union(connection[0], connection[1])
	}
	stationToGrid := make(map[int]*PowerGrid)
	for i := range c {
		i++
		if _, exists := stationToGrid[i]; exists {
			continue
		} else {
			parents := []int{}
			j := i
			for unionFind.parent[j] != j {
				if _, exists := stationToGrid[j]; exists {
					break
				} else {
					parents = append(parents, j)
					j = unionFind.parent[j]
				}
			}
			if _, exists := stationToGrid[j]; !exists {
				stationToGrid[j] = NewPowerGrid(j)
			}
			for _, parent := range parents {
				stationToGrid[parent] = stationToGrid[j]
			}
			stationToGrid[j].AddStations(parents)
		}
	}

	result := []int{}
	for _, query := range queries {
		if query[0] == 1 {
			if _, exists := stationToGrid[query[1]]; !exists {
				result = append(result, -1)
			}
			result = append(result, stationToGrid[query[1]].CurrOrMin(query[1]))
		} else {
			stationToGrid[query[1]].Delete(query[1])
		}
	}

	return result
}
