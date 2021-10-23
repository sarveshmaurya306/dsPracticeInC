#include<bits/stdc++.h>
using namespace std;

 int minccost(vector<int> & cost, int ind, unordered_map< int, int > indCost){
        if(ind>=cost.size())
            return 0;

        if(ind==cost.size()-1)
            return indCost[ind]=cost[ind];

	if(indCost[ind] !=0 ){
		return indCost.at(ind);
	}

        int oneCost= minccost(cost, ind+1, indCost)+ cost[ind]; 
        int twoCost = minccost(cost, ind+2, indCost) + cost[ind];
	return indCost[ind]=min(oneCost, twoCost);
}
    
int minCostClimbingStairs(vector<int>& cost) {
	unordered_map< int, int > indCost;

	int minCost1=minccost(cost, 0, indCost); //0th index
	int minCost2=minccost(cost, 1, indCost); //1th index
	return min(minCost1, minCost2);
}


int main() {
	freopen("input.txt", "r",stdin);
	int s; cin>>s;
	vector<int> vc;
	for(int i=0;i<s;i++){
		int inp; cin>>inp;
		vc.push_back(inp);
	}
	cout<<minCostClimbingStairs(vc)<<endl;
}