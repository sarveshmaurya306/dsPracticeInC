#include<bits/stdc++.h>
using namespace std;

int mcm(int *arr, int i, int j){
        if(i>j)
                return 0;
        for (int k = i; k < j;k++){
                int tempans = function(   mcm(arr, i, k),  mcm(arr, k + 1, j)   );
                ans = function ( tempans );
        }
        return ans;
}

int main() {
        int arr[] = {20, 3, 9, 20};
        cout<<mcm(arr, 0, sizeof(arr) / sizeof(arr[0]));
}