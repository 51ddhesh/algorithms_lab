#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);
    vector<Edge> mst_edges;
    int mst_weight = 0;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_edges.push_back(e);
            mst_weight += e.weight;
        }
    }

    cout << "\nEdges in MST:\n";
    for (Edge e : mst_edges) {
        cout << e.u << " - " << e.v << " (weight: " << e.weight << ")\n";
    }

    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
