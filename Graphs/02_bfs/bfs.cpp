#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &adj, vector<bool> &vis, int vertex){
	queue<int> q;
	q.push(vertex);
	vis[vertex]=true;

	while(!q.empty()){
		int currVertex= q.front();
		q.pop();
		cout<<currVertex<<" ";
		
		for(int relVertex: adj[currVertex]){ //travelling to all vertex which are related to currVertex and pushing into queue
			if(!vis[relVertex]) {
				vis[relVertex]=true;
				q.push(relVertex);
			}
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
			BFS(adj, vis, vertex); //bfs traversal 
			cout<<endl;
		}
	}

}