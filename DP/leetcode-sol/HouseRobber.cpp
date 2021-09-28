#include<bits/stdc++.h>
using namespace std;
    
int rob(vector<int>& nums, int ind=0) {
        //first let's code recursive soln
        if(ind > nums.size())
            return 0;
        
        int liya = nums[ind]+rob(nums, ind+2);
        int nhiliya= rob(nums, ind+1);
        return max(liya, nhiliya);
    
}
int robdp(vector<int> &nums){
        int dp[nums.size()+1];
        dp[0]=nums[0]; 
        if(nums.size() == 1)
                return nums[0];
        
        dp[1]= max(nums[0], nums[1]);
        if(nums.size() == 2)
                return dp[1];
        
        for(int i=2;i<nums.size();i++)
            dp[i] = max( nums[i] + dp[i-2], dp[i-1] );
        
        return dp[nums.size()-1];
}

int main() {
        // vector<int> nums={2,7,9,3,1};
        // vector<int> nums = {1, 2, 3, 1};
        // vector<int> nums={2,0,9,50};
        vector<int> nums = {0};

        cout << rob(nums) << endl;
        cout << robdp(nums) << endl;
}