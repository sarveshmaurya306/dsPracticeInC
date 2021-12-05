#include<bits/stdc++.h>
using namespace std;

bool isOperator(char a){
	if(a=='(' || a=='+' || a=='-' || a==')') return true;
	return false;
}

string change(string s){
	string postfix;
	stack<char> st;
	//if incomming op > top of then simple push
	//if incomming op < top then pop smalleruntil we found the same or greater;

	for(char i: s){
		if(isOperator(i)){
			//cout<<i<<" ";
			if(st.empty()) st.push(i);
			else{
				if(i!=')'){
					if(st.top()=='('){
						st.pop();
						st.push(i);
					}else{
						postfix.push_back(st.top());
						st.pop();
						st.push(i);
					}
				}else{
					while(!st.empty() && st.top()!='('){
						postfix.push_back(st.top());
						st.pop();
					}
					if(!st.empty())
						st.pop();
				}
			}
		}else{
			postfix.push_back(i);
		}
	}
	if(!st.empty() && isOperator(st.top()))
		postfix.push_back(st.top());
	return postfix;
}

int main() {
	freopen("input.txt", "r",stdin);
	//string s="(+(-))";
	
	string s="(1+(4+5+2)-3)+(6+8)";
	cout<<change(s)<<endl;
	
}