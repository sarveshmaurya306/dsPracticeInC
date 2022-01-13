#include<bits/stdc++.h>
using namespace std;

bool CYCLE_BFS(vector<vector<int>>& adj, vector<bool> &vis, int node, int parent){
	queue<pair<int, int> > q; //node -> parent
	q.push({node, -1}); // current is only the top so its parent is -1 (say)
	vis[node]=true;  
	
	while(!q.empty()){
		int top= q.front().first;
		int parent= q.front().second;
		q.pop();

		for(int relVertex: adj[top]){
			if(!vis[relVertex]){
				vis[relVertex]=true; //mark this related vertex so that we never push it to queue again 
				q.push({relVertex, top}); // related, parent
			}
			else if(relVertex !=parent ) return true;
		}
	}
	return false;
}

//driver code
int main() {
	//graph making code
	freopen("../input.txt", "r", stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<int>> adj(n+1); //n+1 for 1 based graph

	while(m--){
		int u, v; cin>>u>>v; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back(v);
		adj[v].push_back(u);  //! for directed comment this line
	}

	//graph cycle detection using bfs
	vector<bool> vis(n+1, false);
	
	for(int vertex=1; vertex<n+1; vertex++){
		if(!vis[vertex]){
			if(CYCLE_BFS(adj, vis, vertex, -1)){
			    cout<<"true"<<endl; //graph has cycle in at least this component
			    return 0;
			}
		}
	}
	
	cout<<"false"<<endl;
}