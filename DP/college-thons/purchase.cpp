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
        return dp[size][W];
}

int main() {
        int w, n;
        cin >> w >> n;
        int arr[n];
        for (int i = 0; i < n;i++)
                cin >> arr[i];

        cout<<maxProfit(arr, w, n)<<endl;
}






/*
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int *arr, int W, int size){
        if(W==0 || size==0){
                return 0;
        }
        if(arr[size-1] > W){
                return 0;
        }
        return max( 
                arr[size-1] + maxProfit(arr, W - arr[size - 1], size - 1) , 
                arr[size-1] + maxProfit(arr, W - arr[size - 1], size)  
        );
}

int main() {
        int w, n;
        cin >> w >> n;
        int arr[n];
        for (int i = 0; i < n;i++)
                cin >> arr[i];

        cout<<maxProfit(arr, w, n)<<endl;
}
*/