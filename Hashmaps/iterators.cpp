#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string, int> mp;
	mp["abc"]=1;
	mp["abc1"]=2;
	mp["abc2"]=3;
	mp["abc3"]=4;
	mp["abc4"]=5;
	mp["abc5"]=6;
		
	map<string, int> ::iterator it;

	it=mp.begin();
	for( ; it!=mp.end(); it++){
		cout<<"key: "<<it->first<<" value "<< it->second<<endl;
	}
	//find
	map<string, int> ::iterator it2 = mp.find("abc2");
	mp.erase(it2);
	
	it=mp.begin();
	for( ; it!=mp.end(); it++){
		cout<<"key: "<<it->first<<" value "<< it->second<<endl;
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1= v.begin();
	for( ;it1!=v.end();it1++){
		cout<<*it1<<endl;
	}
}
