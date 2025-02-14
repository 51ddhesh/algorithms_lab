#include <bits/stdc++.h>
using namespace std;
void DFS(int v, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFS(i, visited, st, adj);
        }
    }
    st.push(v);
}

void topologicalSort(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, visited, st, adj);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    freopen("in.txt", "r", stdin);

    int N; cin >> N;
    int M; cin >> M;
    vector<vector<int>> adj(N);
    // adj[5].push_back(2);
    // adj[5].push_back(0);
    // adj[4].push_back(0);
    // adj[4].push_back(1);
    // adj[2].push_back(3);
    // adj[3].push_back(1);

    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << "Topological Sort of the given graph: ";
    topologicalSort(N, adj);
    return 0;
}