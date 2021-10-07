#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string word, int i, int j){
        while(i<=j){
                if(word[i] != word[j]){
                        return false;
                }
                i++; j--;
        }
        return true;
}

int partition(string word, int i, int j, vector<vector<int>> & dp){
        if(i>=j){ //no string then ans is 0 as well
                return 0;
        }
        if(isPalindrome(word, i, j)){ //palindrome the also the no further partion
                return 0;
        }
        if(dp[i][j]!=-1){
                return dp[i][j];
        }

        int mn= INT_MAX;
        for (int k = i; k <= j-1 ;k++){
                int tempans = partition(word, i, k, dp) + partition(word, k + 1, j, dp) + 1; //1 is for current partition
                mn = min(mn, tempans);
        }
        return dp[i][j]=mn;
}

int main() {
        string word;
        cin >> word;
        //minimum no of partition to make a word palindrome;
        vector<vector<int>> dp(word.length() + 1, vector<int>(word.length() + 1, -1));

        cout << partition(word, 0, word.length() - 1, dp) << endl;
}