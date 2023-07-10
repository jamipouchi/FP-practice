package minDepth

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	Q := []*TreeNode{root}
	depth := 1
	for {
		layerSize := len(Q)
		for i := 0; i < layerSize; i++ {
			node := Q[0]
			Q = Q[1:]
			if node.Left == nil && node.Right == nil {
				return depth
			}
			if node.Left != nil {
				Q = append(Q, node.Left)
			}
			if node.Right != nil {
				Q = append(Q, node.Right)
			}
		}
		depth++
	}
}
