#include<bits/stdc++.h>
using namespace std;

char findNext(vector<char> &arr, char key){

	char res='#';
	int start=0, n= arr.size(), end= n-1;
	while(start<=end){
		int mid= start+(end-start)/2;
		if(arr[mid]==key) { //same then move to right;
			start=mid+1; //! diffrent here
		}
		else if(arr[mid] > key){
			res = arr[mid];
			end= mid-1;
		}
		else if(arr[mid] < key){
			start=mid+1;
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r",stdin);
	//same as finding ceil of an elemetn
	vector<char> arr{'a','c','h','i'};
	cout<<findNext(arr, 'f')<<endl;;
}