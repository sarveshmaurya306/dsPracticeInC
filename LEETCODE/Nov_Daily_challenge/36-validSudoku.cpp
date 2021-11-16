#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

bool checkRow(vector<vector<char>>& board, int row){
	unordered_map<int, int> mp;
	
	for(int i=0;i<9;i++){
		mp[board[row][i]]++;
	}
	for(int i='1';i<='9';i++){
		if(mp[i]>1) return false;
	}
	return true;
}
bool checkCol(vector<vector<char>>& board, int col){
	unordered_map<char, int> mp;
	
	for(int i=0;i<9;i++){
		mp[board[i][col]]++;
	}
	for(int i='1';i<='9';i++){
		if(mp[i]>1) return false;
	}
	return true;
}
bool checkBox(vector<vector<char>>& board, int row, int col){
	int s1=row, e1=col;
	int s2=row+3, e2=col+3;
	unordered_map<char, int> mp;
	
	for(int i=s1;i<s2;i++){
		for(int j=e1;j<e2;j++){
			mp[board[i][j]]++;
		}
	}
	for(int i='1';i<='9';i++){
		if(mp[i]>1) return false;
	}
	return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
	for(int i=0;i<9;i++){
		if(!checkRow(board, i)) return false;
	}
	for(int i=0;i<9;i++){
		if(!checkCol(board, i)) return false;
	}
	for(int i=0;i<9;i=i+3){
		for(int j=0;j<9;j=j+3){
			if(!checkBox(board, i, j)) return false;
		}
	}
	return true;
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	vector<vector<char>> board(9, vector<char>(9));

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			char d; cin>>d; board[i][j]=d;
		}
	}

	cout<<isValidSudoku(board)<<endl;
}