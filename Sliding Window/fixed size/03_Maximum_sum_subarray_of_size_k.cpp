#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& vc, int k){

	int maxi=INT_MIN;
	int sum=0;
	int i=0, j=0;

	while(j<vc.size()){
		sum+=vc[j];

		if(j-i+1<k)
			j++;
		else if(j-i+1 == k){
			maxi=max(maxi, sum);
			sum=sum-vc[i];
			i++;
			j++;
		}
	}

	return maxi;
}

int main() {
	freopen("input.txt", "r",stdin);

	vector<int> vc{
		-2, -3, 4, -1, -2, 1, 5, -3
	};
	int k=3;

	cout<<findMax(vc, k)<<endl;
}