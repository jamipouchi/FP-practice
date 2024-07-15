package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type TreeNodeWithHead struct {
	node   *TreeNode
	isHead bool
}

func createBinaryTree(descriptions [][]int) *TreeNode {
	nodes := make(map[int]TreeNodeWithHead)
	for _, description := range descriptions {
		curr := description[0]
		var currNode *TreeNode
		if node, ok := nodes[curr]; ok {
			currNode = node.node
		} else {
			currNode = &TreeNode{Val: curr}
			nodes[curr] = TreeNodeWithHead{currNode, true}
		}
		child := description[1]
		var childNode *TreeNode
		if node, ok := nodes[child]; ok {
			childNode = node.node
			nodes[child] = TreeNodeWithHead{childNode, false}
		} else {
			childNode = &TreeNode{Val: child}
			nodes[child] = TreeNodeWithHead{childNode, false}
		}
		if description[2] == 1 {
			currNode.Left = childNode
		} else {
			currNode.Right = childNode
		}
	}
	for _, node := range nodes {
		if node.isHead {
			return node.node
		}
	}
	return nil
}
