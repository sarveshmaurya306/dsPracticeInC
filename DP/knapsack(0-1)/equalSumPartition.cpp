#include<bits/stdc++.h>
using namespace std;
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
			} else {
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


bool isEqualPartition(int *arr, int size){
        int sum = 0;
        for (int i = 0; i < size;i++)
                sum += arr[i];
        
        if(sum%2!=0)
                return false;

        int target = sum / 2;
        return subsetSumDp(arr, size, target);
}

int main() {
        int arr[] = {1, 5, 5, 11};
        cout<<isEqualPartition(arr, sizeof(arr) / sizeof(arr[0]));
}