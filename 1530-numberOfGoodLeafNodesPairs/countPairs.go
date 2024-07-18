package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func countPairs(root *TreeNode, distance int) int {
	_, count := countPairsRecursive(root, distance)
	return count
}

func countPairsRecursive(root *TreeNode, distance int) (map[int]int, int) {
	if root == nil {
		return map[int]int{}, 0
	}

	if root.Left == nil && root.Right == nil {
		return map[int]int{1: 1}, 0
	}

	leftMap, leftCount := countPairsRecursive(root.Left, distance)
	rightMap, rightCount := countPairsRecursive(root.Right, distance)

	fmt.Println("Curr node: ", root.Val)
	fmt.Printf("Root: %d, Left: %v, Right: %v\n", root.Val, leftMap, rightMap)

	additionalCount := 0
	for leftDistance, leftValue := range leftMap {
		for rightDistance, rightValue := range rightMap {
			if leftDistance+rightDistance <= distance {
				fmt.Printf("Left: %d, Right: %d, distance: %d\n", leftDistance, rightDistance, distance)
				additionalCount += leftValue * rightValue
			}
		}
	}

	nextDistanceMap := map[int]int{}

	for leftDistance, leftValue := range leftMap {
		if leftDistance+1 < distance {
			nextDistanceMap[leftDistance+1] = leftValue
		}
	}
	for rightDistance, rightValue := range rightMap {
		if rightDistance+1 < distance {
			nextDistanceMap[rightDistance+1] += rightValue
		}
	}
	return nextDistanceMap, leftCount + rightCount + additionalCount
}

// HARDER PROBLEM: Distance between any 2 nodes of the tree
// Recursively we will:
// 1. Build bottom up, the parent decides pairs.

//                      X
//                     / \
//                    Y   Z
//                   / \ / \
//                  A  B C  D

// Ex:
// For node Y, we have (A: 1, B: 1) -> (AY: 1), (BY: 1), (AB: 2)
// For node X, we have (A: 2, B: 2, C: 2, D: 2, Y: 1, Z: 1) -> left: (2: 2, 1: 1), right: (2: 2, 1: 1) -> (4: 4), (4: 3), (1: 2), (2: 1)
