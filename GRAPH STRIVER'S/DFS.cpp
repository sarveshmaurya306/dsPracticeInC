#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, bool *visited, int v){
    visited[v] = true;
    cout << v << " ";
    for(int i: adj[v]){
        if(!visited[i])
            dfs(adj, visited, i);
    }
}

void findDFS(vector<vector<int>> &adj, int n){
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n;i++){
        if(!visited[i]){
            dfs(adj, visited, i);
        }
    }
}

int main() {
    freopen("./input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findDFS(adj, n);
    cout << endl;
}