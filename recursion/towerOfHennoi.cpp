#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

void solve(char s, char h, char d, int n){
	if(n==1) { //bc
		cout<<"move plate "<<n<<" from plate "<<s<<" to "<<d<<endl;
		return;
	}
	solve(s, d, h, n-1); //helper pe legya n-1 disk ko
	//hypothesis
	cout<<"move plate "<<n<<" from plate "<<s<<" to "<<d<<endl;
	//induction step
	solve(h, s, d, n-1); //remaining n-1; put on destination
}

int main() {
	IOS;
	cin.tie(NULL);
	char a='A',b='B',c='C';
	solve(a,b,c,30);
}