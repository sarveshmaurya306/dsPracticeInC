#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(char s[]){
    //base
    if(s[0]=='\0'){
        return;
    }
    //recursion
    //assuming this will give us right answer
    
    removeDuplicate(s+1);

    //calculations
    if(s[0]==s[1]){
        //shift left ;
        int i = 1;
        for (; s[i]!='\0';i++){
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeDuplicate(s);
    }
}


int main() {
    char str[100];
    cin >> str;
    removeDuplicate(str);
    cout << str;
}