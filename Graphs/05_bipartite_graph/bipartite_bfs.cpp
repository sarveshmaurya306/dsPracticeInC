#include<bits/stdc++.h>
using namespace std;

bool BIPARTITE_BFS(vector<vector<int>>& adj, vector<int> &color, int node){
	queue<int> q;
	q.push(node);
	color[node]=1;

	while(!q.empty()){
		int top= q.front();
		q.pop();

		for(int relVertex : adj[top]){
			if(color[relVertex]==-1){ //not been colored then fill with opposite of current color node
				color[top]==1?color[relVertex]=0:color[relVertex]=1;
				// color[relVertex]=1-color[top]; //use upper of use this
				q.push(relVertex);
			} else if(color[relVertex] == color[top]){ //same color then not a bipartite
				return false;
			} else if(color[relVertex]!=color[top]){ //not same color then ok check for next
				continue;
			}
		}
	}
	return true; //every thing is fine 
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

	//bipartitle using bfs
	vector<int> color(n+1, -1);
	
	for(int vertex=1; vertex<n+1; vertex++){ //for all the component
		if(color[vertex]==-1){
			if(BIPARTITE_BFS(adj, color, vertex)==false){ //got even a single then not bipartitle
			    cout<<"NOT A BIPARTITE"<<endl;
			    return 0;
			}
		}
	}
	
	cout<<"BIPARTITE GRAPH"<<endl;
}