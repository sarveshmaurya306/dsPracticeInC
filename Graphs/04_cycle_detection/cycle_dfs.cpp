#include<bits/stdc++.h>
using namespace std;

bool CYCLE_DFS(vector<vector<int>>& adj, vector<bool> &vis, int node, int parent){
	vis[node]=true;
	for(int relVertex: adj[node]){
		if(!vis[relVertex]){ //if related vertex is not visited 
			if(CYCLE_DFS(adj, vis, relVertex, node)) return true;
		} else if( relVertex != parent ) return true; //if related vertex is visited but it is not parent of current node;
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

	//cycle detection using dfs
	vector<bool> vis(n+1, false);
	
	for(int vertex=1; vertex<n+1; vertex++){
		if(!vis[vertex]){
			if(CYCLE_DFS(adj, vis, vertex, -1)){
			    cout<<"true"<<endl; //graph has cycle in at least this component
			    return 0;
			}
		}
	}
	
	cout<<"false"<<endl;
}