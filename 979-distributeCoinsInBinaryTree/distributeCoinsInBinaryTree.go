package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func distributeCoins(root *TreeNode) int {
	totalCost := 0
	var calculateNode func(node *TreeNode) int
	calculateNode = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		leftVal := calculateNode(node.Left)
		rightVal := calculateNode(node.Right)
		nodeVal := node.Val + leftVal + rightVal - 1
		if nodeVal >= 0 {
			totalCost += nodeVal
		} else {
			totalCost -= nodeVal
		}
		return nodeVal
	}
	if root == nil {
		return 0
	}
	calculateNode(root)
	return totalCost
}

// Algorithm:
// 1. Given a node and two children: Subtract 1 to the node value, and also child.val - 1 for each non-nil child or 0 for a nil child
// 2. Apply recursively
// 3. Sum the abs value of all the nodes

// 					OG					BOT-UP
// 					3						0
// 				0		0			  -2		0
// 			1	 0	   0  3			0    -1  -1   2			=> Total Cost: 6

// 				3						 0
// 			0		0               -1		-1				=> Total Cost: 2

//				0						 0
//			3		0				2		-1				=> Total Cost: 3

// Why does it work?
//
// Nodes get coins from parents, and distribute to their children.
// They pay (positive) for their excess (nodes that don't go to direct children), and pay (negative) for what their direct children need
//
// Trivial case: All has 1s. All nodes will add 1 and subtract 1 for each node => Cost 0
// possible combinations:
// 1) 2 1 0 => Parent cost is 0, as it distributes all nodes itself.
// left child cost is 0, right child cost is 1 as it needs to acquire a node
// 2) 3 0 0 => Parent cost is 0, as it distributes all nodes itself.
// left and right cost child is 1, as they need to acquire a node

// 3) 0 3 0 => Parent cost is 0, as it gets a node, but also gives a node.
// left child cost is 2, as it needs to give away 2 nodes not to direct children
// right child cost is 1, as it needs to acquire a node

// CounterExample (top-down) doesn't work:
// 											4 		=>			2
// 										0					-2
// 							  		0					  -2
// 										0					-1

// (bot-up) Works!!
// 											4 		=>			0
// 										0					-3
// 							  		0					  -2
// 										0					-1

// proof:
// If left and right side are balanced, no need to distribute coins
// If left-side needs coins and right side needs coins, we need to pass *2 (get and move)

// 			head
// 	 	 left	right

// The cost of head is:
// Get right excess, move to left needs.
// It could also have some coins so head.Val - 1 (the one it needs to keep)
