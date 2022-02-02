#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr{1,3,0,0,2,4};
	// 3, 4, 2, 2, 4, -1
	int n=arr.size();

	stack<int> st;
	vector<int> nge(n,-1);

	//for(int i=n-1;i>=0;i--){ //next greaters ele from right;
	for(int i=0;i<n;i++){ //nearest greater ele from left;
		int num=arr[i];

		while(!st.empty() && st.top() <= num) st.pop();
		if(!st.empty()) nge[i]=st.top();
		st.push(num);
	}

	for(int i: nge) cout<<i<<" ";
}
