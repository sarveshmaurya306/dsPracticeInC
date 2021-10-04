#include<bits/stdc++.h>
using namespace std;

string printLCSubsequence(string a, string b, int m, int n){
        int dp[m + 1][n + 1];

        //filling dp table; 
        for (int i = 0; i <= m; i++)
                dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
                dp[0][j] = 0;

        for (int i = 1; i <= m;i++){
                for (int j = 1; j <= n;j++){
                        if( a[i-1] == b[j-1])
                                dp[i][j] = dp[i - 1][j - 1] + 1;
                        else 
                                dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
                }
        }

        //now at this pt table is filled
        //time to make string;
        string ans;
        int i = m + 1, j = n + 1;
        while(i>0 && j>0){
                if(a[i-1] == b[j-1]){
                        ans.push_back(a[i - 1]);
                        i--; j--;
                } else {
                        if(dp[i-1][j] > dp[i][j-1]){
                                ans.push_back(a[i - 1]); //line change from printLCSubsequence;
                                i--;
                        }
                        else{
                                ans.push_back(b[j - 1]); //line change from printLCSubsequnce;
                                j--;
                        }
                }
        }
        //line change from printLCSubsequnce begin;

        while(i>0){
                ans.push_back(a[i-1]);
                i--;
        }
        while(j>0){
                ans.push_back(b[j - 1]);
                j--;
        }
        //line change from printLCSubsequnce ends;

        reverse(ans.begin(), ans.end());
        return ans;
}

int main() {
        string a = "AGGTAB";
        string b = "GXTXAYB";
        cout<<printLCSubsequence(a, b, a.length(), b.length())<<endl;
}