#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

void cmb(string s, int n, int ind=0){
	if(n==s.size()) {
		cout<<s<<" ";
		return;
	}
	if(s.empty() || ind>=s.size()) return;
	cmb(s, n, ind+1);

	s.erase(ind, 1);
	cmb(s, n, ind);
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	string st="chp";
	int size=1;
	cmb(st, size);
}