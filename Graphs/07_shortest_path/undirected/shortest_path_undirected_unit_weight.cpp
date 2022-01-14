#include<bits/stdc++.h>
using namespace std;

void shortest_dis(vector<vector<int>> adj, int src){
	int n= adj.size();

	vector<int> dis(n, INT_MAX);

	dis[src]=0;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int top = q.front();

		q.pop();

		for(int relVertex: adj[top]){
			if(dis[relVertex] > 1+dis[top]){ //current is lesser than previous field value; in sdist array
				dis[relVertex]=1+dis[top];
				q.push(relVertex);
			}
		}
	}

	for(int i=1;i<dis.size();i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
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
		adj[v].push_back(u);  //! for directed comment this line
	}

	//graph single src shortest path
	
	shortest_dis(adj, 1);
	
}