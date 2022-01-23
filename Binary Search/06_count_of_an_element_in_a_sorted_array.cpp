#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int lo, int hi, int target, bool findFirstOccurence){
	int ans=-1;

	while(lo<=hi){
		int mid= lo+(hi-lo)/2;
		if(target==arr[mid]){
			if(findFirstOccurence ){
				hi=mid-1; //for firstIndex;
			}else{
				lo=mid+1; //for lastIndex
			}
			ans=mid;
		}
		else if(target < arr[mid])
			hi=mid-1;
		else 
			lo=mid+1;
	}
	return ans;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> arr{2,4,10,10,10,15,20};
	int lo=0, hi=arr.size()-1;
	int target=10;
	
	int firstIndex= binarySearch(arr, lo, hi, target, true);
	int lastIndex=  binarySearch(arr, lo, hi, target, false);

	cout << "total count is : ";
	cout<<lastIndex-firstIndex+1<<endl;
}