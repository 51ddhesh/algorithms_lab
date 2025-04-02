#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int root_X = find(x);
        int root_Y = find(y);
        if(root_X != root_Y) {
            if(rank[root_X] > rank[root_Y]) parent[root_Y] = root_X;
            else if(rank[root_X] < rank[root_Y]) parent[root_X] = root_Y;
            else parent[root_Y] = root_X, rank[root_X]++;
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

int kruskal(int n, vector<Edge> &edges) {
    DSU uf(n);
    int mstWeight = 0;
    sort(edges.begin(), edges.end());
    for(auto &i : edges) {
        int u = i.u;
        int v = i.v;
        int wt = i.weight;
        if(uf.find(u) != uf.find(v)) uf.unite(u, v), mstWeight += wt;
    }
    return mstWeight;
}

int main() {
    int n = 6;
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 3},
        {3, 4, 6},
        {4, 5, 2},
        {2, 5, 7}
    };
    cout << "MST Weight: " << kruskal(n, edges) << '\n';
    return 0;
}