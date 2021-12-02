#include<bits/stdc++.h>
using namespace std;

bool isCycleBFS(vector<vector<int>> &adj, bool *visited, int current, int parent){
    queue<pair<int, int>> q;
    visited[current] = true;
    q.push({current, -1});

    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;

        q.pop();

        for(int it: adj[node]){
            if(!visited[it]){
                 q.push({it, node});
                visited[it] = true;
            } else if(visited[it] && it!=par){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj, int n){
    bool visited[n+1];
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n;i++){
        if(!visited[i]){
            if(isCycleBFS(adj, visited, i, -1)){
                return true;
            }
        }
    }
    return false;
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
    isCycle(adj , n)==1?cout<<"True":cout<<"False";
    cout << endl;
}