#include <bits/stdc++.h>
using namespace std;

int l(string str) {
        if (str == "0")
                return 0;
        if (str == "")
                return 1;

        int digit1 = l(str.substr(1));
        int digit2 = 0;
        if (str.length() >= 2) {
                int x = int(str[0] - '0') * 10 + str[1] - '0';
                if (x <= 26) 
                        digit2 = l(str.substr(2));
        }
        return digit2 + digit1;
}
int main() {
        freopen("input.txt", "r", stdin);
        int t;
        cin >> t;
        while (t--) {
                string str;
                cin >> str;
                int x = l(str);
                if (x!= 0)
                        cout << x << endl;
        }
        return 0;
}

//1,2,1,12,21