#include<bits/stdc++.h>
using namespace std;

int selectMinVertex(vector<int>&dis, vector<bool> &mstset){
	int mini=INT_MAX;
	int vertex;
	for(int i=0;i<dis.size();i++){
		if(mstset[i]==false && dis[i]<mini){
			mini=dis[i];
			vertex=i;
		}
	}
	return vertex;
}

void prims(vector<vector<pair<int,int>>> &adj, int src){
	int n= adj.size();

	vector<int> dis(n, INT_MAX);
	vector<bool> mstSet(n, false);
	vector<int> parent(n,-1);
	
	dis[src]=0;
	parent[src]=-1;

	for(int i=0;i<n-1;i++){
		int u= selectMinVertex(dis, mstSet); //! can replace it with min priority queue
		mstSet[u]=true;

		for(auto relVertex: adj[u]){
			int node= relVertex.first;
			int nodedis= relVertex.second;

			if(mstSet[node]==false && dis[node] > nodedis){
				dis[node]= nodedis;
				parent[node]=u;
			}
		}
	}
	for(int i=1;i<n;i++){
		cout<<dis[i]<<" "<<parent[i]<<endl;
	}

}

//driver code
int main() {
	//graph making code
	freopen("../input.txt", "r", stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<pair<int,int>>> adj(n+1); //n+1 for 1 based graph

	while(m--){
		int u, v, w; cin>>u>>v>>w; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});  //! for directed comment this line
	}
	//mst using prims algo;
	prims(adj, 1);	
}