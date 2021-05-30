#include<bits/stdc++.h>
using namespace std;
#include "dynamicArray.cpp"
int main() {
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    cout<<d1.getCapacity();
    
    /* DynamicArray d2(d1);
    DynamicArray d3;
    d3 = d2;

    d2.addAt(0, 2);
    d1.print();
    d2.print();
    d3.print(); */
}