#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

unordered_map<int, int> dp; //ind, ans    
int numDecodings(string s, int ind=0) {
	if(ind>=s.length()) return 1;
	if(s[ind]=='0') return 0;
	if(dp[ind]!=0) return dp[ind];

	int a= numDecodings(s, ind+1); //1 le skte 
	int b=0;
	if(ind+1<=s.length()-1) {//current and next
		if(stoi(s.substr(ind, 2))<=26)
			b=numDecodings(s, ind+2); //2 le skte
	} 
	return dp[ind]=a+b;
}

int numDecodingsDP(string s){
	if(s.length()==0 || s[0]=='0') return 0;
	int n=s.length();
	
	int dp[n+1]; memset(dp, 0, sizeof(dp));
	dp[0]=1; dp[1]=s[0]!='0'?1:0;
	for(int i=2;i<=n;i++){
		int first= stoi(s.substr(i-1,1));
		int second = stoi(s.substr(i-2,2));
		if(first>=1 && first<=9)
			dp[i]+=dp[i-1];
		if(second>=10 && second<=26)
			dp[i]+=dp[i-2];           
	}
	return dp[n];
}

int main() {
	freopen("input.txt", "r",stdin);
	string s; cin>>s;
	cout<<numDecodings(s)<<endl;
	cout<<numDecodingsDP(s)<<endl;
}