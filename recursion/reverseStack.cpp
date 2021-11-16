/**
 * step 1: first pop all element from stack
 * step 2: insert the top current element into stack by using recursion 
 * call *insetAtLast untill it reaches to end and then push to it ie,. at last;
 * step 3: repeat 
 * step 4: end
 * */

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

void insertAtLast(stack<int> &s, int t){
	if(s.empty()){
		s.push(t);
		return;
	}
	int top= s.top();
	s.pop();
	insertAtLast(s, t);
	s.push(top);
}

void reverseStack(stack<int> & s){
	if(s.empty()) return;
	int t= s.top();
	s.pop();
	reverseStack(s);
	insertAtLast(s, t);
}

int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);

	int n; cin>>n;
	stack<int> s;
	f(i, 0, n){
		int d; cin>>d; s.push(d);
	}	
	reverseStack(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}