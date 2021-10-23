#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    
    int len1 = mid - left + 1;
    int len2 = right - mid;

    int arr1[len1], arr2[len2];

    for(int i=0;i<len1;i++){
        arr1[i] = arr[left+i];
    }
    for(int j=0;j<len2;j++){
        arr2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i<len1 && j<len2){
        if(arr1[i]<=arr2[j]){
            arr[k++] = arr1[i++];
        }else if(arr2[j]<arr1[i]){
            arr[k++] = arr2[j++];
        }
    }
    while(i<len1){
        arr[k++] = arr1[i++];
    }
    while(j<len2){
        arr[k++] = arr2[j++];
    }
}

void mergesort(int arr[], int left, int right){
    if(left>=right){
        return;
    }
    
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {212,21,4,6,9,19,39};
    mergesort(arr, 0, 6);
    for (int i = 0; i < 7;i++){
        cout << arr[i] << " ";
    }
}