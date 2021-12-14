#include<bits/stdc++.h>
using namespace std;

pair <int, int> findMinMax(vector<int> &arr, int start, int end){
	if(start==end)
		return make_pair(arr[start], arr[end]);
	
	if((start+1)==end){
		int a=min(arr[start], arr[end]);
		int b=max(arr[start], arr[end]);
		return make_pair(a,b);
	}
	int mid=start+ (end-start)/2;
	pair<int,int> m,n, ans;

	m=findMinMax(arr, start, mid);
	n=findMinMax(arr, mid+1, end);

	ans.first=min(m.first, n.first);
	ans.second=max(m.second, n.second);
	return ans;
}

int main() {
	freopen("input.txt", "r",stdin);

	int n; cin>>n;
	vector<int> arr(n, 0);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	pair<int,int> ans=findMinMax(arr, 0, n-1);
	cout<<ans.first<<" "<<ans.second<<endl;
}