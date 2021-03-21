#include<stdio.h>
#define MAX 5
int arr[MAX] = {2, 1, 5, 6, 9};

void display(int *ar, int len){
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", *(ar + i));
}

int main() {
    int i, key, j;
    for (i = 0; i < MAX;i++){
        key = arr[i];
        j = i - 1;
        // starting from jth index compaire each element.
        //if the element is greater than our key 
        //than decreate jth value and than check for lesser one.
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr, MAX);
    return 0;
}