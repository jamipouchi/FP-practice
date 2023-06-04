#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    size_t count;

private:
    vector<int> parent;

public:
    UnionFind(size_t n)
    {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void makeUnion(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP != rootQ)
        {
            parent[rootP] = rootQ;
            count--;
        }
    }
};

int findCircleNum(vector<vector<int>> &isConnected)
{
    const int n = isConnected.size();
    UnionFind unionFind(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1)
            {
                unionFind.makeUnion(i, j);
            }
        }
    }
    return unionFind.count;
}
