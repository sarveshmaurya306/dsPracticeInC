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

/*
logic is simple 

step 1: find where to start and where to end
step 2: maintain a visited array so that we keep track of visited indexes, obstacles is -1
step 3: start from start(step1 variable) 
step 4: go to all direction in currenct index ie., left, right, top, bottom; if not visited
step 5: if visited that current index then simply return from there with ans 0; alreay visited
step 6: if current index is not visited and it's on the end(step1 variable) implies we have reached our end index so return;' 1 means 1 path found.
step 7: keep repeating from step 4 to step 6
step 8: stop either we found a valid path or grid overflow
step 9: sum of all direction is our ans;
*/
