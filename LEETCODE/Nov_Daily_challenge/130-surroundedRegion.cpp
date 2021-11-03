#include<bits/stdc++.h>

#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int

using namespace std;
void dfs(vector<vector<char>> &board, int i, int j){
	if(board[i][j]=='O'){
		board[i][j]='1';
		if(i+1<board.size())  dfs(board, i+1, j);
		if(i>1)  dfs(board, i-1, j);
		if(j+1< board[i].size())  dfs(board, i, j+1);
		if(j>1)  dfs(board, i, j-1);
	}
}

void solve(vector<vector<char>> &board){
	if(board.size()==0) return;
	int row= board.size(), col= board[0].size();

	f(i, 0,row){
		dfs(board, i, 0); //convert to 1
		dfs(board, i, col-1); //convert to 1
	}
	f(i, 0, col){
		dfs(board, 0, i);
		dfs(board, row-1, i);
	}
	f(i, 0, row){
		f(j, 0, col){
			if(board[i][j]=='O') board[i][j]='X';
			else if(board[i][j]=='1') board[i][j]='O';
		}
	}
}

int main() {
	freopen("input.txt", "r",stdin);
	vector<vector<char>> board;
	int m, n; cin>>m>>n;
	f(i, 0, m){
		vector<char> temp;
		f(j, 0, n){
			char d; cin>>d;
			temp.push_back(d);
		}
		board.push_back(temp);
	}

	solve(board);
	f(i, 0, board.size()){
		f(j,0, board[0].size()){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}

}