#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(vector<vector<int>> &adj, bool *visited, int current, int parentNode){
    
    visited[current]=true;
    for(int node: adj[current]){
        if(!visited[node]){ //if not visited
            bool child = isCycleDFS(adj, visited, node, current);
            if(child){
                return true;
            }
        } else if(visited[node] && node!=parentNode){ //if already visited
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> & adj, int n){
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n;i++){
        if(!visited[i]){
            if(isCycleDFS(adj, visited, i, -1)){
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