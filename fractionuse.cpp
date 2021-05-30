#include<bits/stdc++.h>
using namespace std;
#include "Fraction.cpp"

int main() {
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.print();
    Fraction f3=++f1;
    ++f3;
    f3.print();
    f1.print();

    // Fraction f4= 

    /* Fraction f3 = f1 + f2;
    Fraction f4 = f1.multiply(f2);
    Fraction f5 = f1 * f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();
    if(f4 == f5)
        cout << "ok";
    else
        cout << "not ok";
    cout << Fraction::getTotalClass();
     */
}