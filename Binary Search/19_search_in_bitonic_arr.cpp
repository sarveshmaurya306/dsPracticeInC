#include<bits/stdc++.h>
using namespace std;

/*!	 bitonic array -> is strictly increasing and strictly decreasing
 w.r.t some point;
	/\
  /   \
/      \ 

to search in it 
	step 1: find the peak element in bitonic array;
	step 2: apply binary search on left; (sorted array binary search)
	step 3: apply binary search on right; (reverse sorted array binary search)
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

int binarySearch_INC_seq(vector<int> &arr, int lo, int hi, int key){
	while(lo<=hi){
		int mid= lo+(hi-lo)/2;

		if(arr[mid]==key) return mid;
		else if(key > arr[mid]) lo=mid+1;
		else hi=mid-1;
	}
	return -1;
}

int binarySearch_DEC_seq(vector<int> &arr, int lo, int hi, int key){
	while(lo<=hi){
		int mid= lo+(hi-lo)/2;

		if(arr[mid]==key) return mid;
		else if(key > arr[mid]) hi=mid-1;
		else lo=mid+1;
	}
	return -1;
}


int main() {
	freopen("input.txt", "r",stdin);
							// 0, 1, 2, 3,  4,  5
	vector<int> arr{1, 3, 8, 12, 4, 2};
	// same logic as finding peak in an array;
	int peakIndex=findPeakIndex(arr);

	int key= 9;
	int leftSearch= binarySearch_INC_seq(arr, 0, peakIndex, key);

	if(leftSearch!=-1) cout<<" element found on index: "<<leftSearch;
	else {
		int rightSearch = binarySearch_DEC_seq(arr, peakIndex+1, arr.size()-1, key);
		if(rightSearch==-1) cout<<"Element not found"<<endl;
		else cout<<"Element found on index: "<<rightSearch;
	}
   // O(logN)
}