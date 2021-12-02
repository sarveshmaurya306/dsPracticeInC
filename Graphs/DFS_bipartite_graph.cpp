#include<bits/stdc++.h>
using namespace std;

bool biparititeDFS(int current, vector<vector<int>> &adj, int *color){
    if(color[current]==-1)
        color[current] = 1;
    
    for(int it: adj[current]){
        if(color[it]==-1){
            color[it] = 1 - color[current];
            if(!biparititeDFS(it, adj, color)){
                return false;
            } else if(color[it]==color[current]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &adj, int n){
    int color[n];
    memset(color, -1, sizeof(color));
    
    for (int i = 1; i <= n; i++){
        if(color[i]==-1){
            if(!biparititeDFS(i, adj, color)){
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

    isBipartite(adj , n)==1?cout<<"Yes":cout<<"No";
    cout << endl;
}