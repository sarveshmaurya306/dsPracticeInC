#include<bits/stdc++.h>
using namespace std;

int sol(int *val, int * wt, int n, int W){
        int dp[n + 1][W + 1];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n + 1;i++){
                for (int j = 0; j < W + 1;j++){
                        if (i == 0 || j == 0)
                                dp[i][j] = 0;
                        else if(wt[i-1]<=j){
                                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                        } else {
                                dp[i][j] = dp[i - 1][j];
                        }
                }
        }
        return dp[n][W];
}

int main() {
        freopen("input.txt","r",stdin);
        int n, W;
        cin >> n >> W;
        int value[n], wt[n];

        for (int i = 0; i < n;i++)
                cin >> value[i];
        for (int i = 0; i < n;i++)
                cin >> wt[i];

        cout<<sol(value, wt, n, W)<<endl;
}