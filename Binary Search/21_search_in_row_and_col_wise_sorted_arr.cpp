/* recursive way for this question */

#include<bits/stdc++.h>
using namespace std;

/*
TC-> O(N+M); 
*/

pair<int,int> binarySearch(vector<vector<int>> &arr, int i, int j, int key){
	int m= arr.size();
	int n= arr[0].size();

	if(i<0 || j<0 || i>=m || j>=n) return make_pair(INT_MIN, INT_MIN);   //not found condition

	int value= arr[i][j];   // for ease purpose only;
	if(value== key) return make_pair(i,j);    //got the key element
	if(key < value) return binarySearch(arr, i, j-1, key);    //key is lesser so move to left
	return binarySearch(arr, i+1, j, key);     //key is greater move to down;
}

int main() {
	
	vector<vector<int>> arr{
		{10,20,30,40},
		{15,25,35,45},
		{27,29,37,48},
		{32,33,39,50}
	};
	//start from; 0, c-1;
	int key= 39;
	pair<int, int> rowCol=binarySearch(arr, 0, arr[0].size()-1, key);

	cout<<rowCol.first<<" "<<rowCol.second<<endl;

}