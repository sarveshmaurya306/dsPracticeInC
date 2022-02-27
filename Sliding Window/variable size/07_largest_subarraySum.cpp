#include<bits/stdc++.h>
using namespace std;



int main() {
	freopen("input.txt", "r",stdin);

	vector<int> vc{4,1,1,1,2,3,5};
	int k=5;
	// both will given

	int size=vc.size();

	int i=0, j=0, maxWindow=0, sum=0;

	while(j<size){
		sum=sum+vc[j];

		if(sum<k) j++;

		else if(sum==k){
			maxWindow = max(maxWindow, j-i+1);
			j++;
		}
		
		else if(sum>k){
			while(sum>k){
				sum=sum-vc[i];
				i++;
			}
			j++;
		}
	}

	cout<<maxWindow<<endl;
}