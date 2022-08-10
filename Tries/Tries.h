//! TO INTIALIZE USE Tries * root= new Tries();
//! TO INSERT USE insert(root, word);
//! TO EXIST OR NOT USE existOrNot(root, word);

#include<bits/stdc++.h>
using namespace std;

class Tries{
	public:
	Tries* links[26];
	bool flag=false;

	friend void insert(Tries *curr, string& word){
		for(int i=0;i<word.size();i++){
			int ind= word[i]-'a';
			if(curr->links[ind]==NULL)
				curr->links[ind]= new Tries();
			curr=curr->links[ind];
		}
		curr->flag=true;
	}

	friend bool existOrNot(Tries* curr, string &word){
		for(int i=0;i<word.size();i++){
			int ind= word[i]-'a';
			if(curr->links[ind]==NULL) return false;
			curr=curr->links[ind];
		}
		return curr->flag;
	}

	friend bool startWith(Tries* curr, string& word){
		for(int i=0;i<word.size();i++){
			int ind= word[i]-'a';
			if(curr->links[ind]==NULL) return false;
			curr=curr->links[ind];
		}
		return true;
	}
};