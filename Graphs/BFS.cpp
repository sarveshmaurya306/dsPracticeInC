#include<bits/stdc++.h>
using namespace std;

void findBFS(vector<vector<int>> &adj, int n){
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()){
                int top = q.front();
                q.pop();
                for (int it : adj[top]){
                    if(!visited[i]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
                cout << top << " ";
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
    findBFS(adj, n);
    cout << endl;
}