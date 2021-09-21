#include<bits/stdc++.h>
using namespace std;

int minSubsetSum(int * arr, int size){
        int range = 0;
        for (int i = 0; i < size;i++)
                range += arr[i];

        //similar to subset sum
        bool dp[size+1][range+1];
	memset(dp, false, sizeof(dp));
	
	for(int i=0;i<size+1;i++)
		dp[i][0] = true;

	for(int i=0;i<range+1;i++)
		dp[0][i] = false;

	for(int i=1;i<size+1;i++){
		for(int j=1;j<range+1;j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			else 
				dp[i][j] = dp[i-1][j];
		}
	}

        //subset sum end
        int mn=INT_MAX;
        for (int j = 0; j < (range + 1) /2 ;j++)
                if(dp[size][j] ) //if this sum is in subset
                        mn= min(mn, range - 2* j);

        return mn;
}

int main() {
        int arr[] = {1, 4, 5, 7, 10};
        cout<< minSubsetSum(arr, sizeof(arr) / sizeof(arr[0]))<<endl;
}