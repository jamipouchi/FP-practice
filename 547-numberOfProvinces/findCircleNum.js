"use strict";
class UnionFind {
    constructor(n) {
        this.count = n;
        this.parent = new Array(n);
        for (let i = 0; i < n; i++) {
            this.parent[i] = i;
        }
    }
    union(i, j) {
        let rootI = this.find(i);
        let rootJ = this.find(j);
        if (rootI !== rootJ) {
            this.parent[rootI] = rootJ;
            this.count--;
        }
    }
    find(i) {
        while (this.parent[i] !== i) {
            this.parent[i] = this.parent[this.parent[i]];
            i = this.parent[i];
        }
        return i;
    }
}
function findCircleNum(isConnected) {
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
}
;
