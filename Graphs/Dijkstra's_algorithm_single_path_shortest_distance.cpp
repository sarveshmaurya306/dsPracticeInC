#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>> &adj, vector<int> &dist){
    priority_queue<pair<int, int>, vector< pair<int,int> >, greater<pair<int,int>>> pq; 
    // min heap {dis, node}
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()){

        pair<int, int> front = pq.top();
        int currDist = front.first;
        int currNode = front.second;
        pq.pop();
        
        for(auto nodes: adj[currNode]){
            //reverse in adj list as compair to dist pair
            int nextNode = nodes.first;
            int nextDist = nodes.second;
            
            if (currDist + nextDist < dist[nextNode]){
                dist[nextNode] = currDist + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }

    }
}

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

    vector<int> dist(n+1, INT_MAX);
    dijkstra(adj, dist);

    for (int it: dist){
        if(it==INT_MAX)
            continue;
        cout << it << " ";
    }
}