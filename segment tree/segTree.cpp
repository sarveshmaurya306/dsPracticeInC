//! # variation if something follow associative property we can use segTree;
// A+(B+c)= (A+B)+C
// +, *, &, |, ^, GCD, min, max  etc...

#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+5;

int tree[4*N];

//tl -> left, tr-> right
void update(int node, int tl, int tr, int ind, int val){
	if(tl==ind and tr==ind){
		tree[node]=val;
		return;
	}
	if(ind> tr || ind<tl){ //outside the range
		return;
	}
	//inside 
	int mid= (tl+tr)/2;
	update(2*node, tl, mid, ind, val);
	update(2*node+1, mid+1, tr, ind, val);

	tree[node]=tree[2*node]+tree[2*node+1];
}

//l, r is query range
int query(int node, int tl, int tr, int l, int r){
	if(tl>r || tr<l) { //outside;
		return 0;
	}
	//full overlap
	if(l<=tl && tr<=r){
		return tree[node];
	}
	
	//partial overlap 
	int mid= (tl+tr)/2;
	int ans=0;
	ans+= query(2*node, tl, mid, l, r);
	ans+= query(2*node+1, mid+1, tr, l, r);

	return ans;
}

int main() {
	//starting node 1-> 2, 3
	//! update-> startNode, start, end, ind, value
	update(1, 0, N-1, 2, 5);
	update(1, 0, N-1, 3, 6);

	//! query-> startNode, start, end, [l, r] get Sum
	cout<<query(1, 0, N-1, 2, 3)<<endl;
}