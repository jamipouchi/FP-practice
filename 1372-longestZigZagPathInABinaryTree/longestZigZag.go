package longestZigZag

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maximum(nums ...int) int {
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

func longestZigZag(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var max int
	var dfs func(node *TreeNode, isLeft bool) int
	dfs = func(node *TreeNode, isLeft bool) int {
		if node == nil {
			return 0
		}
		left := dfs(node.Left, true)
		right := dfs(node.Right, false)
		max = maximum(max, left, right)
		if isLeft {
			return right + 1
		}
		return left + 1
	}
	dfs(root, false)
	return max
}
