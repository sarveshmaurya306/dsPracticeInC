#include<bits/stdc++.h>
using namespace std;

void shortestPathBFS(vector<vector<int>> adj, vector<int> & dis,int n){
    int sourceNode = 0;
    queue<int> q;
    dis[sourceNode] = 0;
    q.push(sourceNode);
    
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for (int adjacentNode : adj[current]){
            if(dis[adjacentNode] > dis[current]+1 ){
                dis[adjacentNode] = dis[current] + 1;
                q.push(adjacentNode);
            }
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

    vector<int> dis(n, INT_MAX);
    shortestPathBFS(adj, dis, n);

    for(int a:dis){
        cout << a << " ";
    }
    cout << endl;
}