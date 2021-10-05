#include<bits/stdc++.h>
using namespace std;

int LCSDP(string a, string b, int m, int n){
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length()+1, -1));
        // base cose => initialization
        for (int i = 0; i <= m;i++)
                dp[i][0] = 0;
        for (int j = 0; j <= n;j++)
                dp[0][j] = 0;

        //choice diagram
        for (int i = 1; i <= m;i++){
                for (int j = 1; j <= n;j++){
                        if (a[i - 1] == b[j - 1] && i!=j) //everything is same as LCS only && is change
                                dp[i][j] = 1 + dp[i - 1][j - 1];
                        else
                                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
        }
        //answer will be on m, n;
        return dp[m][n];
}

int main() {
        string a;
        cin >> a;
        string b=a;
        cout << LCSDP(a, b, a.length(), b.length()) << endl;
}