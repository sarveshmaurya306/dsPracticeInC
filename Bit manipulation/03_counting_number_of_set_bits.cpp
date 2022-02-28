#include<bits/stdc++.h>
using namespace std;


int main() {
	int n=34; // 1100

	int cnt=0;
	while(n>0){
		cnt++;
		n= n & (n-1);
	}
	// time complexity -> O(logn)
	cout<<" cnt "<<cnt<<endl;
}