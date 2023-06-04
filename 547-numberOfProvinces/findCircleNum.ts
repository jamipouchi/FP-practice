class UnionFind {
    private parent: number[];
    count: number;
    constructor(n: number) {
        this.count = n;
        this.parent = new Array(n);
        for (let i = 0; i < n; i++) {
            this.parent[i] = i;
        }
    }
    union(i: number, j: number): void {
        let rootI = this.find(i);
        let rootJ = this.find(j);
        if (rootI !== rootJ) {
            this.parent[rootI] = rootJ;
            this.count--;
        }
    }
    find(i: number): number {
        while (this.parent[i] !== i) {
            this.parent[i] = this.parent[this.parent[i]];
            i = this.parent[i];
        }
        return i;
    }
}


function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    const unionFind = new UnionFind(n);
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < isConnected[i].length; j++) {
            if (isConnected[i][j] === 1) {
                unionFind.union(i, j);
            }
        }
    }
    return unionFind.count;
};