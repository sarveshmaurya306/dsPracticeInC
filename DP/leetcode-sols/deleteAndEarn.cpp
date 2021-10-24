#include<bits/stdc++.h>

#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int

using namespace std;

//only able to write recursive solution
int solve(vector<int>& nums, int ind, unordered_map<int, int> &mp){

        if(nums.size()==ind+1)
            return nums[ind];
	    if(ind>= nums.size())
		    return 0;
        
        if(mp[ind]>0){
            return mp[ind];
        }
        int earnNotDelete = solve(nums, ind+1, mp);
        
        //deleting nums[i]+1 from right;
	    vector<int> num(nums);
        int size= num.size();
        
        while(true){
            auto it = upper_bound(num.begin(), num.end(), nums[ind]);
            if(it==num.end()){
                break;
            }
            if(*it-1 == nums[ind]){
                num.erase(it);
            } else {
                break;
            }
        }
	    
        int earnDelete = solve(num, ind+1, mp) + nums[ind];
        return max(earnDelete, earnNotDelete);

}
int deleteAndEarn(vector<int>& nums) {
	//base condition
	unordered_map<int, int> mp;
	sort(nums.begin(), nums.end());
	return solve(nums, 0, mp);
}

int deleteAndEarnDP(vector<int>& nums) {
        int inc=0;
        int excl=0;
        int arr[10001];  memset(arr, 0, sizeof(arr));
        for(int i: nums){
            arr[i]++;
        }
        for(int i=0;i<10001; i++){
            int ni = excl+ arr[i]*i;
            int ne = max(inc, excl);
            inc= ni; excl= ne;
        }
        return max(inc, excl);
    }

int main() {
	freopen("input.txt", "r",stdin);
	int size; cin >> size; 
	vector<int> vc;
	f(i,0,size){
		int data; cin>>data;
		vc.push_back(data);
	}
	cout<<deleteAndEarn(vc)<<endl;
	cout<<deleteAndEarnDP(vc)<<endl;

}