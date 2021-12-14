#include<bits/stdc++.h>
using namespace std;

string ans;

void printLCS(vector<vector<int>> &dp, string a, string b){
	int i=a.size()+1, j=b.size()+1;
	while(i>=0 and j>=0){
		if(a[i-1]==b[j-1]) {
			ans.push_back(a[i-1]);
			i--, j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}
	}
}

int main() {
	string a="abaaba",b="babbab";
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1]) dp[i][j]= dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		}
	}

	printLCS(dp, a, b);
	cout<<ans;
}