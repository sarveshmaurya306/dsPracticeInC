#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("./input.txt", "r", stdin);
    int n, m; //n -> nodes, m-> edges
    cin >> n >> m;

    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    for(auto it: matrix){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}