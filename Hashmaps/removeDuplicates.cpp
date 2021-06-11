#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int * a, int size){
    unordered_map<int, bool> mp;
    vector<int> vc;

    for (int i = 0; i < size;i++){
        if(mp.count(a[i])>0){
            continue;
        }
        mp[a[i]]=true;
        vc.push_back(a[i]);
    }
    
    return vc;
}

int main() {
    // remove duplicates
    int arr[]= {1, 2, 3, 2, 1, 5, 4, 1, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    vector<int> res=removeDuplicates(arr, length);

    for(int i:res){
        cout << i << " ";
    }
    cout << endl;
}