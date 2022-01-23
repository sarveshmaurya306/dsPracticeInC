#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define ll long long int
#define vc vector
#define pb push_back
using namespace std;
vector<pair<int, int>> directions{ {0, +1},{0, -1},{-1, 0},{+1, 0},{+1, +1},{+1, -1},{-1, -1},{-1, +1} };
/*left, right, up, down
bottom-right, bottom-left, top-left, top-right*/



int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	vc<int> arr{20,17,15,14,13,12,10,8,4,2,1};

	//binary search;
	int lo= 0, hi= arr.size()-1;
	int key= 8;
	while(lo<=hi){
		
		int mid= lo+(hi-lo)/2; // to avoid overflow in integer;
		if(arr[mid] == key) {
			cout<<mid<<endl;
			exit(0);
		}
		else if(key < arr[mid]) 
			lo=mid+1;
		else if(key > arr[mid])
			hi= mid-1;
	}
	
	cout<<"NOT FOUND"<<endl;
}