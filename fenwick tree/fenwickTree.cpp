#include<bits/stdc++.h>
using namespace std;

void update(int ind, int value, vector<int>& bit){
	int n= bit.size(); 
	for( ; ind<=n;ind+= ind&(-ind)){
		bit[ind]+= value;
	}
}

int query(int ind, vector<int>& bit){
	int sum=0;
	for(; ind>0;ind-= ind&(-ind)){
		sum+= bit[ind];
	}
	return sum;
}

int main() {
	freopen("input.txt", "r",stdin);

	int n; cin>>n;
	vector<int> bit(n+1,0);

	for(int i=1;i<=n;i++){
		int data; cin>>data;
		update(i, data, bit);
	}

	cout<<"sum of first 5 ele"<< query(5, bit)<<endl;
	cout<<"sum of elemetn from 2 to 6 "<< query(6, bit)-query(1, bit)<<endl;
}