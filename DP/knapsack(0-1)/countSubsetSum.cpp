#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int size, int target){
        int dp[size + 1][target + 1];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < size + 1;i++){
                dp[i][0] = 1;
        }
        for (int j = 1; j < target + 1;j++){
                dp[0][j] = 0;
        }

        for (int i = 1; i < size + 1;i++){
                for (int j = 1; j < target + 1;j++){
                        if(arr[i-1] <= j){
                                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i - 1][j];
                        } else {
				dp[i][j] = dp[i-1][j];
			}
                }
        }
        return dp[size][target];
}
int main() {
        int arr[] = {2, 3, 5, 6, 8, 10};
        int target = 10;
        cout << countSubsetSum(arr, sizeof(arr) / sizeof(arr[0]), target);
}