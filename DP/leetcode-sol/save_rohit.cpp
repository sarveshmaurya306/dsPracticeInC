#include<bits/stdc++.h>
using namespace std;

void seiveofE(bool *arr, long long n){
        for (long long p = 2; p * p <= n; p++){
        if (arr[p] == true) {
            for (long long i = p * p; i <= n; i += p)
                arr[i] = false;
        }
    }
}

int main() {
        freopen("./input.txt", "r", stdin);
        int t;
        cin>>t;
        while(t--) {
                long long n, k;
                bool isSafe1=false;
                bool isSafe2 = false;

                cin >> n >> k;
                bool arr[n + 1];
                memset(arr, true, sizeof(arr));
                seiveofE(arr, n);
                //prime number done
                long long cntprime = 0;
                for (long long i = 2; i < n + 1;i++){
                        if(arr[i] == true)
                                cntprime++;
                }
                //first condition check 
                //
                if(cntprime >= k){
                        isSafe1 = true;
                }
                long long firstPrime = 2;
                //second condition check
                for (long long i = 3; i < n+1;i++){
                        if(arr[i]){ //if prime
                                if(firstPrime+i+1 == n){
                                        isSafe2 = true;
                                        break;
                                }
                                else{
                                        firstPrime = i;
                                }
                        }
                }

                if(isSafe1 && isSafe2){
                        cout << "UNSAFE" << endl;
                } else {
                        cout << "SAFE"<<endl;
                }
        }
}