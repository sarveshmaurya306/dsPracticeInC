#include<bits/stdc++.h>
using namespace std;

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

    for(auto it: adj){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}