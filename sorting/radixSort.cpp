#include <bits/stdc++.h>
using namespace std;

void display(int *arr, int size){
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void countingSort(int *arr, int size, int dec, int sift){
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < size; i++){
		int temp = arr[i];
		if (sift != 0){
			temp /= sift;
		}
		cnt[temp % dec]++;
	}

	for (int i = 1; i < 10; i++)
		cnt[i] = cnt[i - 1] + cnt[i];

	int newArr[size + 1];

	for (int i = size - 1; i >= 0; i--){
		int temp = arr[i];

		if (sift != 0)
			temp /= sift;
		newArr[--cnt[temp % dec]] = arr[i];
	}

	for (int i = 0; i < size; i++)
		arr[i] = newArr[i];
}

void radixSort(int *arr, int size){
	int max_ele = *max_element(arr, arr + size);

	int t = to_string(max_ele).length();
	int dec = 10;
	int sift = 0;
	while (t--){
		countingSort(arr, size, 10, sift);
		sift = dec;
		dec *= 10;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	radixSort(arr, size);
	display(arr, size);
}
