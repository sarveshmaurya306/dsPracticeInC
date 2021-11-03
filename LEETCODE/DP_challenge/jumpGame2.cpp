#include<bits/stdc++.h>

using namespace std;
int canJump2(vector<int> & nums,int ind, int minJumps, int * dp){
        if(ind>nums.size()-1||nums.size()-ind==1 || ind == nums.size()-1)
            return dp[ind]=0;

        if(nums.size()-ind==2)
            return dp[ind]=1;
	    
        if(dp[ind]!=-1)
            return dp[ind];

        int last = nums[ind];
        if(last >= nums.size())
            return dp[ind]=1;
        
        bool flag= false;
        for(int i=1;i<=last;i++){
            int jumps = canJump2(nums, i+ind, minJumps, dp)+1;
            minJumps=min(jumps, minJumps);
        }
        return dp[ind]=minJumps;
}

int jump(vector<int>& nums) { 
	int dp[100010]; memset(dp, -1, sizeof(dp));
	return canJump2(nums, 0, INT_MAX-9999, dp);
}


int main() {
	freopen("input.txt", "r",stdin);
	
	vector<int> vc;
	int size; cin>>size;
	for(int i=1;i<=size;i++){
		int d ;cin>>d;
		vc.push_back(d);
	}
	cout << jump(vc)<<endl;
}