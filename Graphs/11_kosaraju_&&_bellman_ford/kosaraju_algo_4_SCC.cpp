#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int>> &adj, vector<bool> &vis, stack<int>&st, int vertex){
	vis[vertex]=true;
	for(int relVertex: adj[vertex]){
		if(!vis[relVertex]){
			topoSort(adj, vis, st, relVertex);
		}
	}
	st.push(vertex);
}

void revDFS(vector<vector<int>> &transpose, vector<bool> &vis, int node){
	cout<<node<<" ";
	vis[node]=true;
	for(auto relVertex: transpose[node]){
		if(!vis[relVertex]){
			revDFS(transpose, vis, relVertex);
		}
	}
}

//!main function for SCC
void KOSARAJU_SCC(vector<vector<int>> &adj, vector<bool> &vis, int vertex){
	int n= adj.size();
	//step 1-> sort all node in order of finishing time ie., toposort
	stack<int> st;
	for(int i=1;i<n;i++){
		if(!vis[i]){
			topoSort(adj, vis, st, vertex);
		}
	}

	//step 2-> transpose the graph ie,. reverse the edges
	//reversing the edge direction
	vector<vector<int>> transpose(n);
	for(int i=0;i<n;i++){
		vis[i]=false; //restoring;
		for(auto it: adj[i]){
			transpose[it].push_back(i);
		}
	}

	//step 3-> dfs on topoSort stack;
	while(!st.empty()){
		int node= st.top(); 
		st.pop();
		if(!vis[node]){
			cout<<"SCC: ";
			revDFS(transpose, vis, node);
			cout<<endl;
		}
	}
}

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

	//graph bfs traversal code
	vector<bool> vis(n+1, false);
	
	for(int vertex=1; vertex<n+1; vertex++){ //for all components
		if(!vis[vertex]){
			KOSARAJU_SCC(adj, vis, vertex);
		}
	}

}
/*
5 5
1 2
2 3
3 1
2 4
4 5
*/