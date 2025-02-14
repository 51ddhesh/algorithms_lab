#include <bits/stdc++.h>
using namespace std;

vector<int> dfs;
void DFS(vector<vector<int>> &v, int start, vector<bool> &vis) {
    vis[start] = true;
    dfs.push_back(start);
    for(int i : v[start]) {
        if(!vis[i]) DFS(v, i, vis);
    }   
}

vector<int> BFS(vector<vector<int>> &v, int start) {
    vector<int> bfs;
    vector<bool> vis(v.size(), false);
    queue<int> q;
    vis[start] = true;
    q.push(start);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        bfs.push_back(x);
        for(int i : v[x]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }

    return bfs;
}

void add(vector<vector<int>> &v, int a, int b) {
    v[a].push_back(b);
    v[b].push_back(a);
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        add(v, a, b);
    }

    vector<int> bfs = BFS(v, 0);
    vector<bool> vis_dfs(n, false);
    DFS(v, 0, vis_dfs);
    
    cout << "DFS: ";
    for(int i : dfs) cout << i << " ";
    cout << "\n";

    cout << "BFS: ";
    for(int i : bfs) cout << i << " ";
    cout << "\n";

    return 0;
}