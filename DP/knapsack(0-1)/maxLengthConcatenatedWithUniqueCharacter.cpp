#include<bits/stdc++.h>
using namespace std;

bool isUnique(string str){
        sort(str.begin(), str.end());
        for (int i = 1; i < str.length(); i++)
                if(str[i-1] == str[i])
                        return false;
        return true;
}

int maxLength2(vector<string> & arr, int size, string cstring=""){
        if (size == 0)
                return 0;
        
        int liya=0;

        if( isUnique(cstring+arr[size-1])){
                int cstringLength = arr[size - 1].length();
                liya = cstringLength + maxLength2(arr, size - 1,cstring+arr[size-1]);
        }
        
        int nhiliya = maxLength2(arr, size - 1, cstring);

        return max(liya, nhiliya);
}

//dp
int maxLengthDP(vector<string> & arr, int size){
        
}

int main() {
        vector<string> arr={"abcdefghijklmnopqrstuvwxyz"};
        cout<<maxLength2(arr, arr.size())<<endl;
        cout << isUnique("ueiqun");
}