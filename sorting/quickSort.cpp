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
	int pivot=arr[lo];

	int i=lo;
	int j=hi;
	while(i<j){
		do{
			i++;
		}while(arr[i]<=pivot); //smaller element skip

		do{
			j--;
		}while(arr[j]>pivot); // greater element skip
		if(i<j) //not to swap when i crosses j
			swap(arr[i], arr[j]);
	}
	swap(arr[lo], arr[j]); // j will point to smaller ele than pivot
	return j;
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