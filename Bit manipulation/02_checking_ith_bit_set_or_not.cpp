#include<bits/stdc++.h>
using namespace std;



int main() {
	int n= 12; 
	// (1100);
	int i=2;
	int mask =(1<<i); 
	// 100

	// 1100 & 100 
	if((mask & n) == 0) cout<<"Not set"<<endl;
	else cout<<"set"<<endl;

}