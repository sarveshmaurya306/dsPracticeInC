#include<stdio.h>
#define MAX 6
int arr[MAX] = {2, 7, 4, 1, 5, 3};

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
int main() {
    //! strategy->
    //? go linerly and compare the element with the next element.
    //?if next is greater then swap it otherwise not.
    int i, j;
    for (i = 0; i <MAX-1;i++){
        int flag = 0;//? doing it if the elements are alrady sorted, we can break this loop
        for (j = 0; j < MAX-i-1;j++){
            //compare two element of array and swap them
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = 1; //? element is swapped
            }
        }
        if(flag==0){ //if element is not swapped then break the loop and exit.
            break;
        }
    }
    display(arr, MAX);
    return 0;
}