#include<bits/stdc++.h>
using namespace std;
int findLcs(string a, string b){
        if(a=="" || b=="")
                return 0;
        if(a[0]==b[0])
                return 1 + findLcs(a.substr(1), b.substr(1));
        else
                return max(findLcs(a.substr(1), b), findLcs(a, b.substr(1)));
}
int dpLCS(string a, string b){
        int m = a.size(), n = b.size();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m;i++)
                dp[i][0] = 0;
        for (int j = 0; j <= n;j++)
                dp[0][j]=0;

        for (int i = 1; i <= m;i++){
                for (int j = 1; j <= n;j++){
                        if(a[i-1]==b[j-1])
                                dp[i][j] = 1 + dp[i - 1][j - 1];
                        else
                                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
        }
        return dp[m][n];
}

int main() {
        string a;
        cin >> a;
        string b = a;
        reverse(b.begin(), b.end());
        // int lcslen = findLcs(a, b);
        int lpslen = dpLCS(a, b);
        cout << lpslen << endl;
}