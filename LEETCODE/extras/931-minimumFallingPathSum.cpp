#include<bits/stdc++.h>

#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int

using namespace std;

unordered_map<string , int> dp;

int solve(vector<vector<int>> & matrix,int row, int col) {
	if(col>=matrix.size() || row<0 || col<0){
		return INT_MAX-9999;
	}
	if(row>=matrix.size()) return 0;
	string index = to_string(row)+"_"+to_string(col);

	if(dp[index] !=0 ){
		return dp[index];
	}
	int a=solve(matrix, row+1, col-1) + matrix[row][col];
	int b=solve(matrix, row+1, col) + matrix[row][col];
	int c=solve(matrix, row+1, col+1) + matrix[row][col];
	return dp[index] = min(a,min(b,c));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
	int ans=INT_MAX;
        for(int j=0;j<matrix[0].size();j++)
		ans=min(ans, solve(matrix, 0, j));
	return ans;
}


int main() {
	freopen("input.txt", "r",stdin);
	vector<vector<int> > mat;
	int size; cin>>size;
	for(int i=0;i<size;i++){
		vector<int> temp;
		for(int j=0;j<size;j++){
			int d; cin>>d;
			temp.push_back(d);
		}
		mat.push_back(temp);
	}
	cout<<minFallingPathSum(mat)<<endl;
}