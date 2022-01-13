#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int N, vector<vector<int>> &adj) {
	queue<int> q; 
	vector<int> indegree(N, 0); 
	for(int i = 0;i<N;i++) {
		for(auto it: adj[i]) {
			indegree[it]++; 
		}
	}
	
	for(int i = 0;i<N;i++) {
		if(indegree[i] == 0) {
			q.push(i); 
		}
		cout<<indegree[i]<<endl;
	}
	int cnt = 0;
	while(!q.empty()) {
		int node = q.front(); 
		q.pop(); 
		cnt++; 
		for(auto it : adj[node]) {
			indegree[it]--;
			if(indegree[it] == 0) {
				q.push(it); 
			}
		}
	}

	if(cnt == N) return false; 
	return true; 
}

//driver code
int main() {
	//graph making code
	freopen("../../input.txt", "r", stdin);

	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<vector<int>> adj(n+1); //n+1 for 1 based graph

	while(m--){
		int u, v; cin>>u>>v; //u-> 1st vertex, v-> 2nd vertex
		adj[u].push_back(v);
		//adj[v].push_back(u);  //! for directed comment this line
	}

	//topological sort using bfs
	vector<int> vis(n+1, false);

	cout<<boolalpha<<isCyclic(n, adj);
	
}