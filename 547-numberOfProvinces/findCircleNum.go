type UnionFind struct {
	parent []int
	Count  int
}

func NewUnionFind(n int) *UnionFind {
	parent := make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
	}
	return &UnionFind{
		parent: parent,
		Count:  n,
	}
}

func (this *UnionFind) Union(x, y int) {
	rootX := this.Find(x)
	rootY := this.Find(y)
	if rootX != rootY {
		this.parent[rootX] = rootY
		this.Count--
	}
}

func (this *UnionFind) Find(x int) int {
	if this.parent[x] == x {
		return x
	}
	this.parent[x] = this.Find(this.parent[x])
	return this.parent[x]
}

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	unionFind := NewUnionFind(n)
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if isConnected[i][j] == 1 {
				unionFind.Union(i, j)
			}
		}
	}
	return unionFind.Count
}