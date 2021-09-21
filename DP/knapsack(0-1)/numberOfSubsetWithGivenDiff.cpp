#include<bits/stdc++.h>
using namespace std;

int numberOfSubsetWithGivenDiff(int *arr, int size, int diff){
        int sumarr = 0;
        for (int i = 0; i < size;i++)
                sumarr += arr[i];

        int sum1 = ( diff + sumarr ) / 2;
        int target = sum1;

        //count subset sum code start
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
        //count subset sum code end
        for (int i = 0; i < size + 1;i++){
                for (int j = 0; j < target + 1;j++){
                        cout << dp[i][j] << " ";
                }
                cout << endl;
        }
        return dp[size][target];
}

int main() {
        int arr[] = {1,1,2,3};
        int diff = 2;
        cout << numberOfSubsetWithGivenDiff(arr, sizeof(arr) / sizeof(arr[0]), diff) << endl;
}