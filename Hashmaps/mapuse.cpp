#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	unordered_map<string, int> ourmap;
	//insert 
	pair<string, int> p("abc",1);
	ourmap.insert(p);
	ourmap["def"]=2;
	

	//find or access
	cout<<ourmap["def"]<<endl;
	cout<<ourmap.at("abc")<<endl;

	cout<<ourmap["ghi"]<<endl;

	cout<<"size: "<<ourmap.size()<<endl;

	//check presence
	
	//cout<<ourmap["ghi"]<<endl;
	ourmap["ghi"]=3;
	cout<<"size: "<<ourmap.size()<<endl;

	//check presence
	
	cout<<"erase"<<endl;
	if(ourmap.count("ghi")>0){
		cout<<"ghi is present"<<endl;
	}

	//erase
	ourmap.erase("ghi");

	if(ourmap.count("ghi")>0){
		cout<<"ghi is present"<<endl;
	}else {
		cout<<"ghi is not present"<<endl;
	}
	
	cout<<"size: "<<ourmap.size()<<endl;
}
