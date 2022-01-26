#include<bits/stdc++.h>
using namespace std;
/*
smallest element which is greater than 5;
*/

int findCeil(vector<int> & arr, int x){
	int start=0, n=arr.size(), end=n-1;
	
	int res=-1;

	while(start<=end){
		int mid = start + (end-start)/2;
		if(arr[mid]==x) return arr[mid];

		else if( arr[mid] < x){
			start= mid+1;
		}
		else if(arr[mid] > x){
			res=arr[mid];
			end=mid-1;
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r",stdin);  

	vector<int> arr{1,2,3,4,8,10,12,19};
	int x= 5;
	cout<<findCeil(arr, x);
	
}