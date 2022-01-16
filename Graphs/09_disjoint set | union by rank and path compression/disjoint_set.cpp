#include<bits/stdc++.h>
using namespace std;
#define n 10

int parent[100000];
int rank[100000];

void makeSet(){
	for(int i=1;i<=n;i++){
		::parent[i]=i;
		::rank[i]=0;
	}
}
// 7->6->2->1
int findPar(int node){
	if(node==parent[node]){
		return node;
	}
	return parent[node]=findPar(parent[node]); //path compression
}

void do_union(int u, int v){
	u= findPar(u);
	v= findPar(v);
	if(::rank[u]<::rank[v]){
		parent[u]=v;
	}else if(::rank[v]<::rank[u]){
		parent[v]=u;
	}else {
		parent[v]=u;
		::rank[u]++;
	}
}

int main() {
	makeSet();
	int m; cin>>m;
	while(m--){
		int u, v;
		do_union(u,v);
	}
	if(findPar(2)!=findPar(1))
		cout<<"different componet"<<endl;
	else
		cout<<"same componet"<<endl;
}