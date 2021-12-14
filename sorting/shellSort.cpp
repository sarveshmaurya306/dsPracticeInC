#include<bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr){
	int n= arr.size();
	int gap=n;
	while(gap>=1){
		gap/=2;
		int ptr1=0;
		int ptr2=gap;

		for(int i=0; ;i++){
			if(ptr2>=n) break;
			if(arr[ptr1] > arr[ptr2]){ //swapped find for previous
				swap(arr[ptr1], arr[ptr2]);
				for(int j=ptr1;j>=0;j=j-gap)
					if(arr[ptr1]<arr[j]) swap(arr[ptr1], arr[j]);
			}

			ptr1++, ptr2++;
		}		
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	
	int n; cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	shellSort(arr);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}