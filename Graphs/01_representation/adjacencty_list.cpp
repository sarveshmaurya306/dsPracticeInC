#include<bits/stdc++.h>
using namespace std;

void displayGraph(vector<vector<int>> &adj){
	for(int i=0;i<adj.size();i++){
		cout<<i<<"-> ";
		vector<int> it=adj[i];
		for(int edge: it)
			cout<<edge<<" ";
		cout<<endl;
	}
}

int main() {
	freopen("../input.txt", "r",stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<int>> adj(n+1); //n+1 for 1 based graph

	while(m--){
		int u, v; cin>>u>>v; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back(v);
		adj[v].push_back(u);  //! for directed comment this line
	}

	displayGraph(adj);
}