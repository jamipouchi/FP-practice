package connect

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	layer := []*Node{}
	layer = append(layer, root)
	for len(layer) > 0 {
		nextLayer := []*Node{}
		for i := 0; i < len(layer)-1; i++ {
			layer[i].Next = layer[i+1]
			if layer[i].Left != nil {
				nextLayer = append(nextLayer, layer[i].Left)
			}
			if layer[i].Right != nil {
				nextLayer = append(nextLayer, layer[i].Right)
			}
		}
		last := len(layer) - 1
		if layer[last].Left != nil {
			nextLayer = append(nextLayer, layer[last].Left)
		}	
		if layer[last].Right != nil {
			nextLayer = append(nextLayer, layer[last].Right)
		}
		layer = nextLayer
	}
	return root
}
