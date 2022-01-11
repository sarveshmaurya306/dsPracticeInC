#include<bits/stdc++.h>
using namespace std;

void displayGraph(vector<vector<int>> &adj){
	int n= adj.size();

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" ";
		}
		cout <<endl;
	}
}

int main() {
	freopen("../input.txt", "r",stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<int>> adj(n+1, vector<int>(n+1, 0)); //n+1 for 1 based graph

	while(m--){
		int u, v; cin>>u>>v; //u-> 1st vertex, v-> 2nd vertex
		adj[u][v]=1;
		adj[v][u]=1;  //for directed comment this line
	}

	displayGraph(adj);
}