#include<bits/stdc++.h>
using namespace std;
void display(int *arr, int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

void countingSort(int *arr, int size){
    auto it =max_element(arr, arr+size);
    
    int cnt[*it+1]; memset(cnt, 0, sizeof(cnt));
    
    for(int i=0;i<size;i++)
        cnt[arr[i]]++;
    
    for(int i=1;i<*it+1;i++)
        cnt[i]=cnt[i-1]+cnt[i];
        
    int newArr[size+1];
    
    for(int i=size-1 ;i>=0; i--)
        newArr[--cnt[arr[i]]]=arr[i];
    
    for(int i=0;i<size;i++)
        arr[i]=newArr[i];
}

int main(){
    int size; cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    countingSort(arr, size);
    display(arr, size);
}

