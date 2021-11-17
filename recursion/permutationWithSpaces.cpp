#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

void solve(string s, string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	ans.push_back(s[0]);
	solve(s.substr(1), ans);
	ans.pop_back();
	ans.push_back('_');
	ans.push_back(s[0]);
	solve(s.substr(1), ans);
}

int main() {
	IOS;
	cin.tie(NULL);
	//freopen("input.txt", "r",stdin);
	string a="ABCDE";
	string ans= a.substr(0,1);
	//cout<<ans;
	solve(a.substr(1), ans);
	
}