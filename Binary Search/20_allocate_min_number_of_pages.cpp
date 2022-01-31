#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int k, int max_pages){
	
	int n= arr.size();
	int studentCnt=1, sum=0;

	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum>max_pages){ //if sum > max_pages then start filling next student
			studentCnt++;
			sum=arr[i];
		}

		if(studentCnt>k) return false;
	}

	return true;
}

int allocate_pages(vector<int> & arr, int k){

	if(arr.size() < k) return -1; //books is less and person is more

	int lo= *max_element(arr.begin(), arr.end());
	int hi= accumulate(arr.begin(), arr.end(), 0);

	int res= -1;

	while(lo<=hi){
		int max_pages= lo+(hi-lo)/2;

		if(isValid(arr, k, max_pages)){ //posible;
			res= max_pages;
			hi=max_pages-1;
		}else{
			lo=max_pages+1;
		}
	}

	return res;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> arr{1,2,3,4,5,6,7,8,9,10};
	int person=5;

	cout<<allocate_pages(arr, person);

}