package generatetrees

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type pair struct {
	left, right int
}

var memo = map[pair][]*TreeNode{}

func generateTrees(n int) []*TreeNode {
	return generateTreesRange(pair{1, n})
}

func generateTreesRange(vals pair) []*TreeNode {
	if vals.left > vals.right {
		return []*TreeNode{nil}
	}
	if trees, ok := memo[vals]; ok {
		return trees
	}
	trees := []*TreeNode{}
	for i := vals.left; i <= vals.right; i++ {
		leftTrees := generateTreesRange(pair{vals.left, i - 1})
		rightTrees := generateTreesRange(pair{i + 1, vals.right})
		for _, lTree := range leftTrees {
			for _, rTree := range rightTrees {
				trees = append(trees, &TreeNode{i, lTree, rTree})
			}
		}
	}
	memo[vals] = trees
	return trees
}
