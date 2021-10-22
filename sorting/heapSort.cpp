#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void heapify(int *arr, int n, int i){
    //left 
    int leftInd= 2*i+1;
    int rightInd= 2*i+2;
    int swappedInd=-1;
    
    if(leftInd<n){
        //check swap or not ele
        if(arr[i]<arr[leftInd]){
            swap(arr[i], arr[leftInd]);
            swappedInd=leftInd;
        }
    }
    if(rightInd<n){
        //check swap or not for right ele
        if(arr[i]<arr[rightInd]){
            swap(arr[i], arr[rightInd]);
            swappedInd=rightInd;
        }
    }
    if(swappedInd!=-1)
        heapify(arr, n, swappedInd);
        
}

void heapSort(int *arr, int n){
    if(n==0)
        return;
    //build max heap n/2-1 to 0;
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
    //now swap first and last element 
    //then call heapify on 1 ele
    swap(arr[0], arr[n-1]);
    heapSort(arr, n-1);
    
}

int main(){
    int size; cin>>size;
    int arr[size];
    for(int i=0;i<size;i++) 
        cin>>arr[i];
    heapSort(arr,size);
    display(arr, size);
    cout<<endl;
}
