#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int>> & adj, vector<bool> & vis, stack<int> &st, int node){
	vis[node]=true;

	for(int relVertext : adj[node]){
		if(!vis[relVertext]){
			topoSort(adj, vis, st, relVertext);
		}
	}
	st.push(node);
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
		//adj[v].push_back(u);  //! for directed comment this line
	}

	//topological sort using dfs
	vector<bool> vis(n+1, false);
	stack<int> st;
	
	for(int vertex=1; vertex<n+1; vertex++){
		if(!vis[vertex]){
			topoSort(adj, vis, st, vertex);
		}
	}
	// stack has toposort
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
}