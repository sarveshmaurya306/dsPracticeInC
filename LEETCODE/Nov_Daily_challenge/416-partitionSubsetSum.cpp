#include<bits/stdc++.h>
using namespace std;

vector<int> vc;
    bool flag=false;
    int tsum=0;
    
    int sum(vector<int> &nums){
        int s=0;
        for(int i: nums)
            s+=i;
        return s;
    }
    
    void solve(vector<int>& nums, int ind=0){
        if(flag) return;
        if(ind==nums.size()){
            int a= sum(vc);
            int remain= tsum-a;
            if(a==remain) flag=true;
            return;
        }
        vc.push_back(nums[ind]);
        solve(nums, ind+1);
        vc.pop_back();
        solve(nums, ind+1);
    }
    
    bool canPartition(vector<int>& nums, int ind=0) {
        tsum=sum(nums);
        if(tsum%2!=0) return false;
        solve(nums);
        return flag;
    }

int main() {
	freopen("input.txt", "r",stdin);
	int n; cin>>n;
	vector<int> vc(n, 0);
	for(int i=0;i<n;i++){
		cin>>vc[i];
	}
	canPartition(vc);
	cout<<flag<<endl;
}