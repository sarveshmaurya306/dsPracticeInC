#include<bits/stdc++.h>
using namespace std;

/*!	 bitonic array -> is strictly increasing and strictly decreasing
 w.r.t some point;
	/\
  /   \
/      \ 
*/ 

int findPeakIndex(vector<int> &arr){
	int lo=0, n=arr.size(), hi=n-1;
	while(lo<=hi){
		int mid= lo+(hi-lo)/2;

		if(mid>0 && mid<n-1){
			if(arr[mid]>arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
			else if(arr[mid+1] > arr[mid]) 
				lo=mid+1;
			else 
				hi=mid-1;
		}

		else if(mid==0){
			if(arr[mid]>arr[mid+1]) return 0;
			else return 1;
		}
		else if(mid==n-1){
			if(arr[n-1] > arr[n-2]) return n-1;
			return n-2;
		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> arr{11,12,15,18,2, 5, 6, 8};
	// same logic as finding peak in an array;
	cout<<findPeakIndex(arr)<<endl;
}