#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> & arr, int ele){
    
	int n= arr.size();
	int lo=0, hi=n-1;
	int floor;

	while(lo<=hi){
		int mid= lo+(hi-lo)/2;

		if(ele==arr[mid]) return arr[mid];
		if( arr[mid] < ele) {
			lo=mid+1;
			floor=arr[mid];
		}
		if(arr[mid] > ele){
			hi= mid-1;
		}
	}
	return floor;
}

int main() {
	freopen("input.txt", "r",stdin);
	vector<int> arr{1, 2, 8, 10, 10, 12, 19};
	cout<<findFloor(arr, 9);
}