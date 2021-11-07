#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

char intToChar(int a){
	return ((int)a+(int)'0');
}

string multiply(string num1, string num2) {
	string ans="";
	
	int oneMul= 1;

	for(int i= num1.length()-1;i>=0;i--){
		string rowMul="";
		int carry= 0;
		
		for(int j=num2.length()-1;j>=0;j--){
			int a= num1[i]- '0', b=num2[j] -'0';
			int mul= (a*b)+carry;
			//cout<<a<<" "<<b<<" ";
			//cout<<" "<<mul<<endl;
			int currentDigit= mul %10;
			carry=mul/10;
			char digitIntChar=intToChar(currentDigit);
			//cout<<digitIntChar<<" "<<carry<<endl;
			rowMul.push_back(digitIntChar);
			//cout<<currentDigit<<endl;
		}
		//cout<<endl;
		if(carry!=0)
			rowMul.push_back(intToChar(carry));
		reverse(rowMul.begin(), rowMul.end());
		if(ans!="")
			ans=to_string(stoi(ans)+(stoi(rowMul)*oneMul));
		else
			ans=to_string((stoi(rowMul)*oneMul));
		oneMul*=10;
		//cout<<ans<<endl;
	}
	//cout<<ans<<endl;
	return ans;
}
//can do this via array

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);
	string s1="1238988", s2="456";
	cout<<multiply(s1, s2)<<endl;
}