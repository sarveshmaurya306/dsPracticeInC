#include<bits/stdc++.h>
using namespace std;
#include "Pair.h"
//we are using .h file becouse we restring Pair to not to use one more main file

int main() {
    Pair<int, int > p;

    Pair< Pair<int, int>, int> p2;

    p2.setY(10);

    Pair<int, int> p4;
    p4.setX(40);
    p4.setY(50);

    p2.setX(p4);

    cout << p2.getX().getX()<<" " << p2.getX().getY()<<" "<< p2.getY();
}