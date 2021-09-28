#include<bits/stdc++.h>
using namespace std;

long long maze(vector<vector<long long >> &arr, long long i, long long j, long long a, long long b){
    if(i>=a || j>=b){
        return 99999;
    }
    if(i ==a-1 && j== b-1){
        return arr[i][j];
    }
    // right, down , diagonal
    long long rightans = arr[i][j] + maze(arr, i, j + 1, a, b);
    long long downans =arr[i][j] + maze(arr, i + 1, j, a, b);
    long long diagonal = arr[i][j] + maze(arr, i + 1, j + 1, a, b);
    // cout << rightans << " " << downans <<" "<< diagonal << endl;
    return min(rightans, min(downans, diagonal));
}

int main(){
    freopen("input.txt", "r", stdin);
    long long a, b;
    cin >> a >> b;
    vector<vector<long long>> arr(a, vector<long long>(b,0));

    for (long long i = 0; i < a;i++){
        for (long long j = 0; j < b;j++){
            cin >> arr[i][j];
        }
    }
    //input done;

    cout << maze(arr, 0, 0, a, b) << endl;
}