#include<bits/stdc++.h>

#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector

using namespace std;

unordered_map<string, int> dp;
int uniquePaths(vector<vector<int>>& obstacleGrid, int i, int j) {
	int m= obstacleGrid.size(), n= obstacleGrid[0].size();

	if(i==m-1 && j==n-1){
		if(obstacleGrid[i][j]==0) return 1;
		else return 0;
	}

	if(i>=m || j>=n || obstacleGrid[i][j]==1) return 0;

	string index= to_string(i)+"_"+to_string(j);
	if(dp[index]!=0) return dp[index];
	return dp[index]=uniquePaths(obstacleGrid, i+1, j)+uniquePaths(obstacleGrid, i, j+1);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	return uniquePaths(obstacleGrid, 0, 0);
}

int main() {
	freopen("input.txt", "r",stdin);
	int m, n; cin>>m>>n;
	vc<vc<int>> obstacleGrid(m, vector<int>(n, 0));

	f(i,0,m){
		f(j,0,n){
			int d; cin>>d;
			obstacleGrid[i][j]=d;
		}
	}
	cout<<uniquePathsWithObstacles(obstacleGrid)<<endl;
}