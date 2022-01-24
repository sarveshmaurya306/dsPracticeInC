#include<bits/stdc++.h>
using namespace std;

int findMinIndex(vector<int> & nums){
	int n=nums.size();
	int lo=0, hi=n-1;
	while(lo<=hi){
		int mid= lo+(hi-lo)/2;
		int pre=(mid-1+n)%n, next= (mid+1)%n;
		
		if(nums[mid] <= nums[pre] && nums[mid] <= nums[next]) return mid;
		else if(nums[mid] <= nums[hi])
			hi= mid-1;
		else if(nums[mid] >= nums[lo])
			lo= mid+1;
	}
	return -1;
}

int search(vector<int>& nums, int target) {
	
	int minIndex = findMinIndex(nums);
	int rot=minIndex;
	int lo=0, n=nums.size(), hi=n-1;
	
		while(lo<=hi){
		int mid=(lo+hi)/2;
		int realmid=(mid+rot)%n;
		if(nums[realmid]==target)return realmid;
		if(nums[realmid]<target)lo=mid+1;
		else hi=mid-1;
	}
	return -1;
}

int main() {
	vector<int> arr{15,13,1,3,5,7};
	cout<<search(arr, 1);
}