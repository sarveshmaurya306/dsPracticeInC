#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &arr, int target){
	int n=arr.size(), lo= 0, hi =n-1;
	while(lo<= hi){
		int mid= lo+(hi-lo)/2;

		if(mid-1>=0 && arr[mid-1]==target) return mid-1;
		if(mid+1<= n-1 && arr[mid+1]==target) return mid+1;
		if(arr[mid]==target) return mid;
		
		if(target < arr[mid]) {
			hi = mid-2;
		}else if(target>arr[mid]){
			lo=mid+2;
		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> arr{5,10,30,20,40};
	cout<<find(arr, 5);
	
}