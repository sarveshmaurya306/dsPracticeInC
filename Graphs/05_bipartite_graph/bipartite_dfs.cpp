#include<bits/stdc++.h>
using namespace std;

bool BIPARTITE_DFS(vector<vector<int>>& adj, vector<int> &color, int node){
	int currentColor= color[node];
	 //first element
	if(currentColor==-1) color[node]=1;
	
	//check for other related node and color;
	for(int relVertex: adj[node]){
		if(color[relVertex]==color[node]){ //how two vertex can have same color;
			return false;
		} else if(color[relVertex]==-1){ //fill adjacent node to other color
			color[node]==1 ? color[relVertex]=0 : color[relVertex]=1; //fill other color which is not still visited;
			bool isOk= BIPARTITE_DFS(adj, color, relVertex);
			if(!isOk) return false; //if one node has not bipartitle then return false;

		} else if(color[relVertex]!=color[node]){ //if not have same color then all is fine
			continue;
		}
	}
	return true; //when everything is fine
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

	//bipartitle using dfs
	vector<int> color(n+1, -1);
	
	for(int vertex=1; vertex<n+1; vertex++){ //for all sapared component
		if(color[vertex]==-1){
			if(BIPARTITE_DFS(adj, color, vertex)==false){ //got even a single then not bipartitle
			    cout<<"NOT A BIPARTITE"<<endl;
			    return 0;
			}
		}
	}
	
	cout<<"BIPARTITE GRAPH"<<endl;
}