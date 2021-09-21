#include<bits/stdc++.h>
using namespace std;
//RECURSION
bool subsetSum(int *arr, int size ,int tar){
	if(tar==0){
		return true;
	}
	if(size==0){
		return false;
	}
	if(arr[size-1] <= tar){	
		int taken= subsetSum(arr, size-1, tar-arr[size-1]);
		int notTaken= subsetSum(arr, size-1, tar);
		return taken || notTaken;
	}
	return subsetSum(arr, size-1, tar);
}
//DP
int subsetSumDp(int *arr, int size, int tar){
	bool dp[size+1][tar+1];
	memset(dp, false, sizeof(dp));
	
	for(int i=0;i<size+1;i++){
		dp[i][0] = true;
	}

	for(int i=0;i<tar+1;i++){
		dp[0][i] = false;
	}

	for(int i=1;i<size+1;i++){
		for(int j=1;j<tar+1;j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	/* 
	for(int i=0;i<size+1;i++){
		for(int j=0;j<tar+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	 */
	return dp[size][tar];
}

int main(){
	
	int arr[]={ 3, 34, 4, 12, 5, 2 };
	int target=9;
	cout << endl<<subsetSum(arr, sizeof(arr)/sizeof(arr[0]) ,target)<<endl;
	cout<<subsetSumDp(arr, sizeof(arr)/sizeof(arr[0]), target)<<endl;
}
