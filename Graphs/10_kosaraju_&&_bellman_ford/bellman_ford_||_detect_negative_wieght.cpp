 #include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int u, v, wt;
	Node(int f, int s, int t){
		u=f, v=s, wt=t;
	}
};

int main() {
	//graph making code
	freopen("../input.txt", "r", stdin);
	
	int n,m; cin>>n>>m; //n-> vertex, m-> edges
	vector<Node> edges; //n+1 for 1 based graph

	while(m--){
		int u, v, w; cin>>u>>v>>w; //u-> 1st vertex, v-> 2nd vertex
		Node *x= new Node(u,v,w);

		edges.push_back(*x);
	}

	//bellman ford algo
	vector<int> dis(n+1, INT_MAX);
	//detecting negative weight

	//run till N-1 times;
	
	int src=1;
	dis[src]=0;

	for(int i=1;i<=n-1;i++){
		for(auto edge: edges){ //going through all edges and
			int  u= edge.u,
			v= edge.v,
			w= edge.wt;
			if(dis[u] + w < dis[v]){ //relaxation 
				dis[v]= dis[u]+w;
			}
		}
	}

	bool isNegativeCycle=false;
	//one more relaxation for negative cycle;
	for(auto edge: edges){
		int  u= edge.u,
		v= edge.v,
		w= edge.wt;
		if(dis[u] + w < dis[v]){ //relaxation 
			isNegativeCycle=true;
			break;
		}
	}

	if(isNegativeCycle) cout<<"Negative cycle detected";
	else cout<<"No negative cycle";
}