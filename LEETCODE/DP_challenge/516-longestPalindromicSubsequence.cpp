#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

int solve(string s, string b){
	int m=s.length(), n=b.length();
	if(m==0 || n==0) return 0;
	
	if(s[0]==b[0]){
		return 1+solve(s.substr(1), b.substr(1));
	}
	return max(solve(s.substr(1),b), solve(s, b.substr(1)));
	
}
    
int longestPalindromeSubseq(string s) {
	string temp=s;
	reverse(s.begin(), s.end());
	return solve(s, temp);
}

int longestPalindromeSubseqDP(string s) {
	string b=s;
	reverse(s.begin(), s.end());
	int n=s.length();
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(s[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else {
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}

int main() {
	IOS;
	cin.tie(NULL);
	string s="kicozfownolm";
	cout<<longestPalindromeSubseqDP(s)<<endl;
	cout<<longestPalindromeSubseq(s)<<endl;
}