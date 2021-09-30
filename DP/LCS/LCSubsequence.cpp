#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n,vector<vector<int>> &dp){
        if(n==0 || m ==0)
                return 0;
        
        if(dp[m][n] != -1){
                return dp[m][n];
        }

        if (a[m - 1] == b[n - 1])
                return dp[m][n] = 1 + LCS(a, b, m - 1, n - 1, dp);
        return dp[m][n]= max( LCS(a, b, n - 1, m,dp), LCS(a, b, n, m - 1,dp) );
}

int main() {
        string a,b ;
        cin >> a >> b;
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length()+1, -1));
        cout << LCS(a, b, a.length(), b.length(), dp) << endl;
}