#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generate(int rows){
	vector<int> c;
	vector<vector<int> > ans;
	c.push_back(1);
	if(rows==1){
		ans.push_back(c);
		return ans;
	}
	ans.push_back(c); //1
	c.push_back(1); //1 , 1 1
	ans.push_back(c);
	
	if(rows==2)
		return ans;

	for(int i=1;i<rows-1;i++){
		vector<int> temp; temp.push_back(1);
		vector<int> before= ans[i];
		
		for(int j=1;j<before.size();j++){
			int sum = before[j-1]+before[j];
			temp.push_back(sum);
		}
		temp.push_back(1);
		ans.push_back(temp);
	}
	
	return ans;
}


int main() {
	//freopen("input.txt", "r",stdin);
	
	int row; cin>>row;
	vector<vector<int>> ans =generate(row);
	for(auto it: ans){
		for(int i:it){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}