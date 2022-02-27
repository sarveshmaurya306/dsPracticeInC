#include<bits/stdc++.h>
using namespace std;



int main() {
	freopen("input.txt", "r",stdin);

	string s= "timetopractice";
	string t= "toc";

	unordered_map<char, int> mp;
        int minlen=INT_MAX, start=0;
        for(auto ch:t)
            mp[ch]++;
        
        int i=0,j=0,count=mp.size();
        
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){ //if present;
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count==0){ //when count ==0 every character is present in this window;
                while(count==0){ //minimizing the window size;
                    if(mp.find(s[i])!=mp.end()){ // has character
                        mp[s[i]]++;
                        if(mp[s[i]]==1) { //as soon has one character inc yet to find(count var)
                            count++;
                            if(j-i+1<minlen){ //updating the minimum;
                                minlen=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }  
            }
            j++;
        }
        if(minlen==INT_MAX) cout<<"null";
		else cout<<s.substr(start, minlen);

}