package main

import (
	"container/heap"
	"slices"
)

type Item struct {
	Value int
	Index int
}

type MinHeap []Item

func (h MinHeap) Len() int {
	return len(h)
}
func (h MinHeap) Less(i, j int) bool {
	return h[i].Value < h[j].Value
}
func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *MinHeap) Push(x any) {
	item := x.(Item)
	*h = append(*h, item)
}
func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[0 : n-1]
	return item
}

func maxSubsequence(nums []int, k int) []int {
	minHeap := &MinHeap{}
	heap.Init(minHeap)

	for i, num := range nums {
		heap.Push(minHeap, Item{Value: num, Index: i})
		if minHeap.Len() > k {
			heap.Pop(minHeap)
		}
	}

	slices.SortFunc(*minHeap, func(a, b Item) int {
		return a.Index - b.Index
	})

	result := make([]int, k)
	for i, item := range *minHeap {
		result[i] = item.Value
	}

	return result
}

// nlogk + klogk ~> nlogk
