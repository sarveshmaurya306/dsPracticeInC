#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

string ans="";
vector<string> mans;

void caseChange(string s){
	if(s.size()==0) {
		mans.push_back(ans);
		return;
	}

	if((s[0]>='a' and s[0]<='z') or (s[0]>='A' and s[0]<='Z')){
		ans.push_back(s[0]);
		caseChange(s.substr(1));
		ans.pop_back();

		char toPush=(s[0]>='A' and s[0]<='Z')?tolower(s[0]):toupper(s[0]);

		ans.push_back(toPush);
		caseChange(s.substr(1));
		ans.pop_back();
		return;
	}
	ans.push_back(s[0]);
	caseChange(s.substr(1));
	ans.pop_back();
}

vector<string> letterCasePermutation(string s) {
	caseChange(s);
	return mans;
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	string s="a1b2";
	letterCasePermutation(s);
	for(auto i: mans){
		for(char j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}