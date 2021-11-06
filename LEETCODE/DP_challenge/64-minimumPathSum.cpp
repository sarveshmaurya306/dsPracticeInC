#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

class Solution{
	public:
		unordered_map <string, int> ans;

		int solve(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){

			int m=grid.size();
			int n=grid[0].size();
			
			if(i>=m || j>=n || i<0 || j<0 || visited[i][j]) return INT_MAX-9999;
			
			if(i==m-1 && j==n-1) return grid[i][j];
			
			string index= to_string(i)+"_"+to_string(j);
			if(ans[index]!=0) return ans[index];
			
			visited[i][j]=true;
			
			int a=solve(grid, visited, i+1, j)+grid[i][j];
			int b=solve(grid, visited, i, j+1)+grid[i][j];
			
			visited[i][j]=false;
			
			return ans[index]=min(a,b);
		}
		int minPathSum(vector<vector<int>>& grid) {
			int m=grid.size(), n=grid[0].size();
			vector<vector<bool>> visited(m, vector<bool>(n, false));
			
			return solve(grid, visited, 0 ,0);
		}
};
int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);
	
	int m, n; cin>>m>>n;
	vector<vector<int>> grid;
	
	f(i,0,m){
		vc<int> temp;
		f(j,0,n){
			int d; cin>>d;
			temp.push_back(d);
		}
		grid.push_back(temp);
	}
	Solution *s= new Solution();
	cout<<s->minPathSum(grid)<<endl;
}