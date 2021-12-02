#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;


void generate(int open, int close, string store){
	if(open==0 and close==0){
		cout<<store<<endl;
		return;
	}
	if(open!=0){
		store.push_back('(');
		generate(open-1, close, store);
		store.pop_back();
	}
	if(close > open){
		store.push_back(')');
		generate(open, close-1, store);
		store.pop_back();
	}
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	int a=5;
	int open=a;
	int close=a;
	string store="";
	store.push_back('(');
	generate(open-1, close, store);
}