package allnodesdistancekinbinarytree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Graph = map[int][]int

func distanceK(root *TreeNode, target *TreeNode, k int) []int {

	graph := Graph{}
	buildGraph(root, -1, graph)

	return getNeighborsAtDistanceK(target.Val, k, graph)

}

func buildGraph(node *TreeNode, parent int, graph Graph) {

	if parent != -1 { // takes care of root
		graph[node.Val] = []int{parent}
	}

	if node.Left != nil {
		buildGraph(node.Left, node.Val, graph)
		graph[node.Val] = append(graph[node.Val], node.Left.Val)
	}
	if node.Right != nil {
		buildGraph(node.Right, node.Val, graph)
		graph[node.Val] = append(graph[node.Val], node.Right.Val)
	}
}

func getNeighborsAtDistanceK(origin int, distance int, graph Graph) []int {

	layer := []int{origin}
	visited := make(map[int]struct{})
	seen := struct{}{}
	visited[origin] = seen

	for distance > 0 {
		nextLayer := []int{}
		for _, node := range layer {
			for _, neighbor := range graph[node] {
				if _, ok := visited[neighbor]; !ok {
					visited[neighbor] = seen
					nextLayer = append(nextLayer, neighbor)
				}
			}
		}
		distance--
		layer = nextLayer
	}
	return layer
}
