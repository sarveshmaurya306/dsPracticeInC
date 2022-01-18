#include<bits/stdc++.h>
using namespace std;

void dfs(int node, 
		int parent, 
		vector<bool> &vis, 
		vector<int> & tin, 
		vector<int>& low, int &timer, 
		vector<vector<int>> &adj
	)	{

	vis[node]=true;
	tin[node]= low[node]=timer++;
	for(auto relVertex: adj[node]){
		//not running for selft;
		if(!vis[relVertex]){

			dfs(relVertex, node, vis, tin, low, timer, adj);
			
			low[node]= min(low[node], low[relVertex]);
			if(low[relVertex] > tin[node]){
				cout<<node<<" "<<relVertex<<endl;
			}
		}
		else {
			low[node]= min(low[node], tin[relVertex]);
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
	vector<int> low(n+1, -1);
	vector<int> tin(n+1, -1);
	int timer=0;
	
	for(int vertex=1; vertex<n+1; vertex++){ //for all components
		if(!vis[vertex]){
			dfs(vertex, -1, vis, tin, low, timer, adj);
		}
	}

}