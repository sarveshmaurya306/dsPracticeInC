#include <iostream>

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    int arr[5] = {3, 2, 1, 5, 4};
    mergesort(arr, 0, 4);
    for (auto el : arr)
    {
        std::cout << el << std::endl;
    }
}

void mergesort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

void merge(int arr[], int s, int mid, int e)
{
    int i = s;
    int j = mid + 1;
    int k = 0;

    int temp[e - s + 1];

    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= e)
    {
        temp[k++] = arr[j++];
    }

    for (i = s, k = 0; i <= e; i++, k++)
    {
        arr[i] = temp[k];
    }
}