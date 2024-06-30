package main

type UnionFind struct {
	parent []int
	rank   []int
	count  int
}

func NewUnionFind(n int) *UnionFind {
	rank := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		rank[i] = 1
	}
	parent := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		parent[i] = i
	}
	return &UnionFind{
		parent: parent,
		rank:   rank,
		count:  n,
	}
}

func (uf *UnionFind) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x])
	}
	return uf.parent[x]
}

func (uf *UnionFind) Union(x, y int) bool {
	rootX := uf.Find(x)
	rootY := uf.Find(y)
	if rootX == rootY {
		return false
	}
	if uf.rank[rootX] < uf.rank[rootY] {
		rootX, rootY = rootY, rootX
	}
	uf.parent[rootY] = rootX
	uf.rank[rootX] += uf.rank[rootY]
	uf.count--
	return true
}

func (uf *UnionFind) IsConnected() bool {
	return uf.count == 1
}

func maxNumEdgesToRemove(n int, edges [][]int) int {
	alice := NewUnionFind(n)
	bob := NewUnionFind(n)

	edgesUsed := 0

	for _, edge := range edges {
		if edge[0] == 3 {
			aliceUnited := alice.Union(edge[1], edge[2])
			bobUnited := bob.Union(edge[1], edge[2])
			if aliceUnited || bobUnited {
				edgesUsed++
			}
		}
	}
	for _, edge := range edges {
		if edge[0] == 1 {
			if alice.Union(edge[1], edge[2]) {
				edgesUsed++
			}
		}
		if edge[0] == 2 {
			if bob.Union(edge[1], edge[2]) {
				edgesUsed++
			}
		}
	}

	if alice.IsConnected() && bob.IsConnected() {
		return len(edges) - edgesUsed
	} else {
		return -1
	}
}
