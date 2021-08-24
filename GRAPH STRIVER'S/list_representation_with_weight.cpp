#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("./input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> >> adj(n+1);
    for (int i = 0; i < m;i++){
        int u, v, w; // u --w--- u w=weight
        cin >> u >> v>> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int cnt=0;
    for(auto it: adj){
        cout<<cnt++<<" ";
        for(auto i:it){
            cout <<" E " << i.first<<" w "<<i.second << " ";
        }
        cout << endl;
    }
}