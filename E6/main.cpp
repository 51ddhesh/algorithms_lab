#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
int V; 
vector<vector<pair<int, int>>> mst;

void dfs(int u, vector<bool>& visited, vector<int>& preorder) {
    visited[u] = true;
    preorder.push_back(u);
    for (auto& [v, w] : mst[u]) {
        if (!visited[v]) {
            dfs(v, visited, preorder);
        }
    }
}

int primMST(const vector<vector<int>>& graph) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;
    int mst_weight = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1, minKey = INF;

        for (int v = 0; v < V; ++v)
            if (!inMST[v] && key[v] < minKey)
                minKey = key[v], u = v;

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    mst.assign(V, vector<pair<int, int>>());
    for (int i = 1; i < V; ++i) {
        int u = parent[i];
        int v = i;
        int w = graph[u][v];
        mst[u].emplace_back(v, w);
        mst[v].emplace_back(u, w);
        mst_weight += w;
    }

    return mst_weight;
}

int calculateTourWeight(const vector<int>& tour, const vector<vector<int>>& graph) {
    int weight = 0;
    for (int i = 0; i < tour.size() - 1; ++i) {
        weight += graph[tour[i]][tour[i + 1]];
    }
    weight += graph[tour.back()][tour[0]];
    return weight;
}

int main() {
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    int mst_weight = primMST(graph);

    vector<bool> visited(V, false);
    vector<int> preorder;

    dfs(0, visited, preorder);
    preorder.push_back(0); 
    int tour_weight = calculateTourWeight(preorder, graph);

    double approximation_ratio = (double)tour_weight / mst_weight;

    cout << "\nPreorder TSP Tour:\n";
    for (int v : preorder) cout << v << " ";
    cout << "\nTour weight: " << tour_weight;
    cout << "\nMST weight: " << mst_weight;
    cout << "\nApproximation ratio: " << approximation_ratio << endl;

    return 0;
}
