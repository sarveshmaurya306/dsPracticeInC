#include<bits/stdc++.h>
#include "Tries.h"
using namespace std;

int main() {
	Tries * root= new Tries();
	vector<string> words{"hello", "hey","hellomana"}	;
	vector<string> search{"fasd"};

	for(string &s: words) 
		insert(root, s);

	for(string &s: words)
		cout<<boolalpha<<existOrNot(root, s)<<endl;
	
}