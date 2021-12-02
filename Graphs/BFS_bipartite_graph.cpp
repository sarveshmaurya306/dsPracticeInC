#include<bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int current, vector<vector<int>>&adj, int *color){
    queue<int> q;
    q.push(current);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int it: adj[node]){
            if(color[it]==-1){
                color[it] = 1 - color[node];
                q.push(it);
            } else if(color[it]==color[node]){ //at least one does not follow rule
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>&adj, int n){
    int color[n + 1];
    memset(color, -1, sizeof(color));

    for (int i = 1; i <= n;i++){
        if(color[i]==-1){
            if(!bipartiteBfs(i, adj, color)){
                return false;
            }
        }
    }
    return true;
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

    isBipartite(adj, n) == 1 ? cout << "Yes" : cout << "No";
    cout << endl;
}