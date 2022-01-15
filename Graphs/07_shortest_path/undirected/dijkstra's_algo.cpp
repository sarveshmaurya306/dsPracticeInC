#include<bits/stdc++.h>
using namespace std;

void shortest_dis(vector<vector<pair<int, int>>> &adj, int src){
	int n= adj.size();

	priority_queue<pair<int,int>, vector<pair<int, int>> , greater<pair<int,int>> >pq;
	//dis-> node
	vector<int> dis(n, INT_MAX);
	dis[src]=0;
	pq.push({0, src});

	while(!pq.empty()){
		//int cdist= pq.top().first;
		int node= pq.top().second;
		pq.pop();

		for(auto relVertex: adj[node]){
			int next= relVertex.first;
			int nextDis= relVertex.second;

			if(dis[next] > dis[node] + nextDis){//!
				dis[next]=dis[node]+ nextDis;
				pq.push({dis[next], next});
			}
		}
	}

	//dis array has distance;
	for(int i: dis){
		cout<<i<<" ";
	}
}


//driver code
int main() {
	//graph making code
	freopen("../../input.txt", "r", stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<pair<int,int>>> adj(n+1); //n+1 for 1 based graph

	while(m--){
		int u, v,w; cin>>u>>v>>w; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});  //! for directed comment this line
	}

	//graph single src shortest path
	//via dijkstra algo
	shortest_dis(adj, 1);
	
}