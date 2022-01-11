#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj, vector<bool> &vis, int vertex){
	cout << vertex <<" ";
	vis[vertex]=true;
	for(int relVertex: adj[vertex]){
		if(!vis[relVertex]){
			DFS(adj, vis, relVertex);
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
		adj[v].push_back(u);  //! for directed comment this line
	}

	//graph bfs traversal code
	vector<bool> vis(n+1, false);
	
	int countComponents=0; //for counting different countComponents
	for(int vertex=1; vertex<n+1; vertex++){
		if(!vis[vertex]){
			cout<<"component "<<countComponents++<<"-> ";
			DFS(adj, vis, vertex); //bfs traversal 
			cout<<endl;
		}
	}

}