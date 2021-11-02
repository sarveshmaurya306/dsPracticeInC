#include<bits/stdc++.h>

#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int

using namespace std;

bool isAllVisited(vector<vector<int>>& visited){
	for(int i=0;i<visited.size();i++){
		for(int j=0;j<visited[0].size();j++){
			if(visited[i][j]==0){
				return false;
			}
		}
	}
	return true;
}

int solve(vector<vector<int>>& grid, vector<vector<int>>& visited, pair<int, int>& end, int i, int j){
	//base condition
	cout<<i<<" "<<j<<" yo endl "<<endl;
	f(i,0,grid.size()){
		f(j,0, grid[0].size()){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==-1){
		return 0;
	}

	int temp= visited[i][j];
	visited[i][j]=1;

	if(i==end.first && j== end.second){
		if(isAllVisited(visited))
			return 1;
		else
			return 0;
	}
	
	if(temp==0){
		int a=solve(grid, visited, end, i+1, j);
		int b= solve(grid, visited, end, i-1, j);
		int c=solve(grid, visited, end, i, j+1);
		int d=solve(grid, visited, end, i, j-1);
		visited[i][j]=temp;
		return a+b+c+d;
	}
	
	return 0;
}


int uniquePathsIII(vector<vector<int>>& grid) {
	vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), 0));
	pair<int, int> start, end;
	int m= grid.size(), n= grid[0].size();

	for(int i=0; i<m; i++ ){
		for(int j=0; j<n;j++){
			if(grid[i][j]==1)	start=make_pair(i,j);
			if(grid[i][j]==2)	end=make_pair(i,j);

			if(grid[i][j]==-1){
				visited[i][j]=-1;
			}
		}
	}
	//cout<<start.first<<" "<<start.second<<endl;
	
	return solve(grid, visited, end, start.first, start.second);
}

int main() {
	freopen("input.txt", "r",stdin);
	int m, n; cin>>m>>n;
	vector<vector<int>> grid;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int d; cin>>d;
			temp.push_back(d);
		}
		grid.push_back(temp);
	}
	cout<<uniquePathsIII(grid);
}