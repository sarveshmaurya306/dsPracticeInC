#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int>& arr, vector<vector<int>> &dp, int start, int end);

int cnt=1;

void printParenthesis(int i, int j, vector<vector<int>> &bracket){
	if(i>bracket.size() || j>bracket.size()) return;
	if(i==j){ 
		cout<<"A"<<cnt++;
		return;
	}
	cout<<"(";
	printParenthesis(i, bracket[i][j], bracket);
	printParenthesis(bracket[i][j]+1, j, bracket);
	cout<<")";
}


int mcmdp(vector<int>&arr){
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(n,0));
	vector<vector<int>> bracket(n, vector<int>(n,0));

	for(int L=2;L<n;L++){
		for(int i=1;i<n-L+1;i++){
			int j=i+L-1;
			dp[i][j]=INT_MAX;
			for(int k=i; k<j;k++){
				int q= dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(q<dp[i][j]) {
					dp[i][j]=q;
					bracket[i][j]=k;
				}
			}
		}
	}

	printParenthesis(1, n-1, bracket);
	cout<<endl;
	
	return dp[1][n-1];
}

int main() {
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	vector<int> arr(n, 0);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<vector<int>> dp(n, vector<int>(n,-1));

	//cout<<mcm(arr, dp, 1,n-1);	
	mcmdp(arr);
	
}



int mcm(vector<int>& arr, vector<vector<int>> &dp, int start, int end){
	if(start==end) return 0;
	if(dp[start][end]!=-1) return dp[start][end];

	dp[start][end]=INT_MAX;

	for(int i=start; i<end;i++){
		dp[start][end]=min(
			dp[start][end], 
			mcm(arr, dp, start, i) + mcm(arr, dp, i+1, end)+( arr[start-1] * arr[i] * arr[end])
		);
	}
	return dp[start][end];
}
