#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

string ans="";

void gen(int n, int one, int zero){
	if(n==0){
		cout<<ans<<endl;
		return;
	}
	//always have option to include 1
	ans.push_back('1');
	gen(n-1, one+1, zero);
	ans.pop_back();

	if(one-zero>=1){ //option to include zero
		ans.push_back('0');
		gen(n-1, one, zero+1);
		ans.pop_back();
		return;
	}
	
}

int main() {
	IOS;
	cin.tie(NULL);

	int n; cin>>n;
	int one=0;
	int zero=0;
	ans.push_back('1');
	gen(n-1, one+1, zero);
}