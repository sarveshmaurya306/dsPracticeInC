#include<bits/stdc++.h>
using namespace std;

void display(int* arr, int lo, int hi){
        for (int i = lo; i < hi;i++)
                cout<<arr[i]<<" ";
        cout << endl;
}
//? important to see this partition
int partition(int *arr, int lo, int hi){
        //place firtst element on its right place
        //and return its index;
        int pivot = arr[lo];
        int p1 = lo + 1;
        for(int i=lo+1;i<=hi;i++){
                if(arr[i]<pivot){
                        if(i!=p1){
                                swap(arr[p1], arr[i]);
                        } 
                        p1++;
                }       
        }

        arr[lo]=arr[p1-1];
        arr[p1-1]=pivot;

        return p1-1;
}

void quickSort(int *arr, int lo, int hi){
        if(lo<hi){
                int pivotIndex = partition(arr, lo, hi);
                quickSort(arr, lo, pivotIndex - 1); //first small part
                quickSort(arr, pivotIndex + 1, hi); //second small part
        }
}

int main() {
        freopen("input.txt", "r", stdin);
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size;i++)
                cin >> arr[i];
        //input done
        int low = 0;
        int high = size;
        quickSort(arr, low, high);

        //print
        display(arr, 0, high);
}