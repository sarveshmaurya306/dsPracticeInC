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

	vc<int> arr{2,4,10,10,10,18,20};

	int lo=0, hi= arr.size()-1;
	int key=10;

	int ans=-1; //! possible ans;

	while(lo<=hi){
		int mid= lo+(hi-lo)/2;
		if(arr[mid]==key){
		    cout<<mid<<endl;
			hi=mid-1; //for find first occurence uncomment this and comment below one
 			//lo=mid+1; //for find last occurence uncomment this and comment upper one

			ans=mid;
		}else if(key < arr[mid])
			hi=mid-1;
		else 
			lo=mid+1;
	}

	//! ans contains first or last occurence
	cout<<ans<<endl;
}