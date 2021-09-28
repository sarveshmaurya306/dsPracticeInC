#include <bits/stdc++.h>
using namespace std;

string findCommon(string a, string b){

        string maxstr = "";
        for (int i = 0, j = 0; i < a.length() && j < b.length();){
                if(a[i]==b[j]){
                        maxstr += a[i];
                        i++, j++;
                } else {
                        i++;
                }
        }
        string maxstr2="";
        for (int i = 0, j = 0; i < a.length() && j < b.length();){
                if(a[i]==b[j]){
                        maxstr2 += a[i];
                        i++, j++;
                } else {
                        j++;
                }
        }

        return maxstr.length()>maxstr2.length()?maxstr:maxstr2;
}

int main(){
        freopen("input.txt", "r", stdin);
        int n;
        cin >> n;
        string str[n];
        for (int i = 0; i < n; i++)
                cin >> str[i];
        string ans = str[0];
        for (int i = 1; i < n; i++){
                cout << ans<<" "<<str[i] << endl;
                ans=findCommon(ans, str[i]);
        }
        cout << ans << endl;
}