#include <stdio.h>
#define MAX 6
int arr[MAX] = {10, 2, 90, 10, 4, 1};
//0, 1, 2, 3, 4, 5

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *ar, int len){
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", *(ar + i));
}
void main(){
    int i = 0, j = 0;
    
    //!strategy ->
    //? 1)choose smallest element in right part of array after completion;
    //? 2)swap it with the current i'th index of array;

    for (i = 0; i < MAX - 1; i++){

        int imin = i; //let array has minimum element at index i;

        //serching for minimum element index in right array;
        for (j = i + 1; j < MAX; j++)
            if (arr[j] < arr[imin])
                imin = j;
        
        //swaping elements;
        swap(&arr[imin], &arr[i]);
    }
    //displaying the element of array.
    display(arr, MAX);
}