#include<bits/stdc++.h>
using namespace std;

int findMinDiffEle(vector<int> & arr, int key){
	int lo=0, n=arr.size(), hi=n-1;

	while(lo<=hi){
		int mid = lo+(hi-lo)/2;

		if(arr[mid]==key) return arr[mid];

		if(key < arr[mid]) hi= mid-1;
		else if(key > arr[mid]) lo=mid+1;
	}

	//here lo is pointing to the right lowest closest mid diff ele
	// and hi is pointing to the left lowest closest mid diff ele
	int a= abs(key- arr[lo]);
	int b= abs(key- arr[hi]);

	int mini= min(a,b);
	return mini==a?arr[lo]:arr[hi];
}

int main() {
	vector<int> arr{1,3,8,10,15};
	int key= 12;
	cout<<findMinDiffEle(arr, key)<<endl;;
}  