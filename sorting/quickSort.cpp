#include<bits/stdc++.h>
using namespace std;

void display(int* arr, int lo, int hi){
        for (int i = lo; i < hi;i++)
                cout<<arr[i]<<" ";
        cout << endl;
}
//? important to see this partition
int partition(int *arr, int lo, int hi){
	int pivot = arr[lo], 
		leftptr = lo, 
		rightptr = hi+1;
	while (leftptr < rightptr) {
		do {
			leftptr++;
		} while (arr[leftptr] <= pivot); 
		//smaller element skip
		do {
			rightptr--;
		} while (arr[rightptr] > pivot); 
		// greater element skip
		if (leftptr < rightptr) //not to swap when l>r
			swap(arr[leftptr], arr[rightptr]);
	}
	swap(arr[lo], arr[rightptr]); 
	// rightptr point pivot index;
	return rightptr;
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
        int size; cin >> size;
        int arr[size];
        for (int i = 0; i < size;i++)
                cin >> arr[i];
        //input done
        int low = 0;
        int high = size;
		cout<<"before quick sort"<<endl;
		display(arr, 0, high);

        quickSort(arr, low, high);
		
        cout<<"after quick sort"<<endl;
        display(arr, 0, high);
}