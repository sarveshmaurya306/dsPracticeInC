#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

int cntSetBits(int n){
	int count=0;
	while(n!=0){
		n = n&(n-1);
		count++;
	}
	return count;
}

int main() {
	IOS;
	cin.tie(NULL);
	int b=7;
	cout<<cntSetBits(b);
	
	
}