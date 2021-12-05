#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;


vector<pair<int, int>> directions{ {0, +1},{0, -1},{-1, 0},{+1, 0},{+1, +1},{+1, -1},{-1, -1},{-1, +1} };
/*left, right, up, down
bottom-right, bottom-left, top-left, top-right*/

int cnt=0;

void findPath(vector<vector<int>> & board, int r, int c){
	int n=board.size();
	if(r<0 || c<0 || r==n || c==n||board[r][c]) return;

	if(r==n-1 and c==n-1) {
		board[r][c]=1;
		cnt++;
		for(auto it: board){
			for(int i: it){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		board[r][c]=0;
		return;
	}

	for(int i=0;i<4;i++){
		board[r][c]=1;
		if(i==1 || i==2) continue; //only left and down allowed
		findPath(board, r+directions[i].first, c+directions[i].second);
		board[r][c]=0;
	}
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	vector<vector<int>> board(4, vector<int>(4,0));
	board[1][0]=2;
	board[1][2]=2;
	board[1][3]=2;
	//board[3][2]=2;
	findPath(board, 0, 0);
	cout<<cnt<<endl;
}
