/**
 * idea is pop out all element one by one and keep value of array size as well as mid
 * when recursion come where current == mid we do nothing 
 * other wise we push that current element into the stack
 * */

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fi(i, s, e, j) for (int i = s; i < e; i = i + j)
#define ll long long int
#define vc vector
using namespace std;

int totalcnt=0;
int size=0;
int mid=0;

void deleteMiddle(stack<int> &s){
	if(s.empty()){
		size=totalcnt; // saving for next
		mid= (totalcnt/2) +1; //finding middle
		return;
	}
	int t = s.top();
	s.pop();
	totalcnt++;
	deleteMiddle(s);
	totalcnt--;
	if(totalcnt==mid) //current is equal to middle do nothing
		return;
	s.push(t); //else part
}

int main(){
	IOS;
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int size;
	cin >> size;
	stack<int> s;
	f(i, 0, size){
		int d;	cin >> d; s.push(d);
	}
	deleteMiddle(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}