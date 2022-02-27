#include<bits/stdc++.h>
using namespace std;



int main() {
	freopen("input.txt", "r",stdin);

	string s= "abaccab";
	int k=2;

	unordered_map<char, int> mp;

	int ans=0, i=0, j=0;
	while(j<s.size()){
		
		mp[s[j]]++;
		
		if(mp.size()<k){
			j++;
		} else if(mp.size()==k){
			ans=max(ans, j-i+1);
			j++;
		} else if(mp.size() > k){
			while(mp.size() > k){
				mp[s[i]]--;
				if(mp[s[i]] == 0) mp.erase(s[i]);
				i++;
			}
			j++;
		}

	}

	cout<<ans<<endl;

}