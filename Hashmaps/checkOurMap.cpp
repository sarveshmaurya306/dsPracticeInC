#include<bits/stdc++.h>
#include "OurMap.h"
using namespace std;

int main() {
    ourmap<int> map;
    for (int i = 0; i < 10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }
    //abc0 1, abc1 2 ...etc
    cout << "size: "<<map.size()<<endl;

    map.remove("abc2");
    map.remove("abc7");
    
    cout << "size: "<<map.size()<<endl;

    for (int i = 0; i < 10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;

        cout << "key: " <<key<<" value: "<< map.getValue(key) << endl;
    }
}