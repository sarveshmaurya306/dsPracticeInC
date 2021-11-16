/**
 * step 1: Pop out all element in stack
 * step 2: then insert elements one by one
 * step 3: if the current value element is less: then pop out top and do the same recursivelly and after when fun return push the top ele
 * step 4: if the current is greater than the top : then simply push into the stack
 * step 5: end
 * */

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for(int i=s; i<e; i++)
#define fi(i, s, e, j) for(int i=s;i<e;i=i+j)
#define ll long long int
#define vc vector
using namespace std;

void sorting(stack<int> & st, int val){
    if(st.empty()){
		st.push(val);
		return;
	}
    int t= st.top();
    if(val>t){
        st.pop();
        sorting(st, val);
        st.push(t);
    }else
		st.push(val);
}
void sortStack(stack<int>& s){
    if(s.empty()) return;
    int t = s.top();
    s.pop();
    sortStack(s);
    sorting(s, t);
}
int main() {
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r",stdin);
	int size; cin>>size;
	stack<int> st;

	f(i, 0, size){
		int d; cin>>d; st.push(d);
	}

	sortStack(st);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}