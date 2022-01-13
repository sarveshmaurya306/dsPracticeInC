#include<bits/stdc++.h>
using namespace std;

void topoSort_bfs(vector<vector<int>> & adj, vector<int> & indegree, vector<int> &ans, vector<int> &vis){
	queue<int> q;
	//push all indegree 0 into q;
	for(int i=1;i<indegree.size();i++){
		if(indegree[i]==0) {
			vis[i]=true;
			q.push(i);
		}
	}

	//bfs start
	while(!q.empty()){
		int top = q.front();
		ans.push_back(top);
		q.pop();

		for(int relVertex : adj[top]){                                   
			indegree[relVertex]--;
			if(indegree[relVertex]==0) {
				vis[relVertex]=true;
				q.push(relVertex);
			}
		}
	}
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
		//adj[v].push_back(u);  //! for directed comment this line
	}

	//topological sort using bfs
	vector<int> vis(n+1, false);

	//indegree array
	vector<int> indegree(n+1, 0);
	vector<int> ans;
	
	//indegree counting
	for(int i=1;i<n+1;i++){
		for(int relVertex : adj[i]){
			indegree[relVertex]++;
		}
	}

	for(int i=1;i<n+1;i++){
		if(!vis[i]){ //for multiple component
			topoSort_bfs(adj, indegree, ans, vis);
		}
	}
	//ans has the topological sort
	for(int i : ans){
		cout<<i<<" ";
	}
}