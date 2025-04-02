#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, wt;
    bool operator>(const Edge &e) const {
        return wt > e.wt;  
    }
};

void prim(int n, vector<vector<pair<int, int>>> &adj) {
    vector<bool> inMST(n, false);  
    vector<int> parent(n, -1);  
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  
    
    pq.push({0, 0});  
    int mst_weight = 0;

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int u = edge.v;
        int weight = edge.wt;
        if (inMST[u]) continue;
        inMST[u] = true;
        mst_weight += weight;

        for(auto &i : adj[u]) {
            int v = i.first, w = i.second;
            if (!inMST[v]) pq.push({v, w}), parent[v] = u; 
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << '\n';
        }
    }
    cout << "Minimum Spanning Tree Cost: " << mst_weight << '\n';
}


int main() {
    int n = 6;      
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});
    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});
    adj[4].push_back({5, 2});
    adj[5].push_back({4, 2});
    adj[2].push_back({5, 7});
    adj[5].push_back({2, 7});
    
    prim(n, adj);
    
    return 0;
}