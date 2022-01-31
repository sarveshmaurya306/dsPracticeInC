#include<bits/stdc++.h>
using namespace std;

/*
	go to most promising part of the array as we only need to return on peak only
	move toward the higher side of the array and find
*/

int findPeak(vector<int> &arr){

	if(arr.size()<=1) return arr.size()-1;

	int lo=0, n=arr.size(), hi=n-1;

	while(lo<=hi){
		int mid= lo+(hi-lo)/2;
		if(mid>0 && mid<n-1){ //mid is not at start and end of the array;
			if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return arr[mid]; //this is ans
			else if(arr[mid-1] > arr[mid]){ //bde vale ki trf move kiya
				hi=mid-1;
			}
			else if(arr[mid+1] > arr[mid]){
				lo=mid+1;
			}
		}

		else if(mid==0) { //mid start
			if(arr[mid] > arr[mid+1]) return arr[mid];
			else return arr[mid+1];
		}
		else if(mid==n-1) { //mid end
			if(arr[mid] > arr[n-2]) return arr[mid];
			else return arr[n-2];
		}
	}
	//if not found
	return -1;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> arr{1,2,1,3,5,6,4};

	cout<<"maximum element is: "<<findPeak(arr)<<endl;

}