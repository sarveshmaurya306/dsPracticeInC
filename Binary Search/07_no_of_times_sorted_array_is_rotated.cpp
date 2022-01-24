#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr{11,12,15,18,2,5,8};
	int n= arr.size();
	int start=0, end= n-1;

	while(start<=end){
		int mid= (start+end)/2;

		int next = (mid+1)%n;
		int prev = (mid+n-1)%n;
		if( arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
			cout<<"time array is rotated is "<<mid<<endl;
			break;
		} 
		
		//! show some attention
		else if(arr[mid] <= arr[end]){ //right is sorted move in left(unsorted)
			end= mid-1;
		}
		else if(arr[start] <= arr[mid]){ //left is sorted move right(unsorted)
			start=mid+1;
		} 
	}
	
}


/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n= nums.size();
        int left = 0, right = nums.size() -1 ;
        
        if(nums[right] > nums[left]) return nums[0];
        
        while(left<right){
            int mid =left+(right-left)/2;
            
            if(nums[mid]<nums[right])
                right= mid;
            else
                left=mid+1;
        }
        return nums[left];
    }
};
*/
