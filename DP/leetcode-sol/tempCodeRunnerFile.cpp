#include<bits/stdc++.h>
using namespace std;

int maxProfit(int *arr, int W, int size){
        int dp[size + 1][W + 1];
        for (int i = 0; i < size + 1;i++)
                dp[i][0] = 1;
        for (int j= 1; j< W + 1;j++)
                dp[0][j] = 0;

        for (int i = 1; i < size + 1;i++){
                for (int j = 1; j < W + 1;j++){
                        if(arr[i-1] <= j)
                                dp[i][j] = max(arr[i - 1] + dp[i][j - arr[i - 1]], dp[i - 1][j]);
                        else 
                                dp[i][j]= dp[i-1][j];
                }
        }
}

int main() {
        int w, n;
        cin >> w >> n;
        int arr[n];
        for (int i = 0; i < n;i++)
                cin >> arr[i];

        cout<<maxProfit(arr, w, n)<<endl;
}