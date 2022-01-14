#include<bits/stdc++.h>
using namespace std;

void topoSort_dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &topo, int node){
	vis[node]=true;
	for(auto it: adj[node]){
		int relVertex= it.first;
		int wt = it.second;
		if(!vis[relVertex]){
			topoSort_dfs(adj, vis, topo, relVertex);
		}
	}
	topo.push(node);
}

void shortest_dis_dag(vector<vector<pair<int,int>>> &adj, int src){
	int n= adj.size();

	vector<bool> vis(n, false);
	stack<int> st;
	for(int i=1;i<n;i++){ //for all compo
		if(!vis[i]){
			topoSort_dfs(adj, vis, st, 1);
		}
	}
	//topo sort done;
	
	vector<int> dis(n, INT_MAX);
	dis[src]=0;

	while(!st.empty()){
		int node= st.top();
		st.pop();

		if(dis[node]!=INT_MAX){
			for(auto it: adj[node]){
				if(dis[node]+ it.second < dis[it.first]){
					dis[it.first] = dis[node]+it.second;
				}
			}
		}
	}

	for(int i=1;i<n;i++){
		cout<<i<<" "<<dis[i]<<endl;
	}
}


//driver code
int main() {
	//graph making code
	freopen("../../input.txt", "r", stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<pair<int, int>>> adj(n+1); //n+1 for 1 based graph
	//u->v->w

	while(m--){
		int u, v,w; cin>>u>>v>>w; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back({v,w});
		//adj[v].push_back(u);  //! for directed comment this line
	}

	//graph single src shortest path in DAG with wieght
	
	shortest_dis_dag(adj, 1);
	
}