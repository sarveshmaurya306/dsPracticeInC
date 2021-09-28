#include<bits/stdc++.h>
using namespace std;

int main() {
        string word;
        cin >> word;
        unordered_map<char, int> wordcnt;
        for (int i = 0; i < word.size();i++){
                wordcnt[word[i]]++;
        }
        pair<char, int> firstoddcnt;
        int oddCount = 0;
        for(auto it:wordcnt){
                if(it.second %2 != 0){
                        firstoddcnt.first = it.first;
                        firstoddcnt.second = it.second;
                        oddCount++;
                }
        }

        if(oddCount > 1){
                cout << "NOT POSSIBLE" << endl;
                return 0;
        }

        deque<char> ans; 
        for (int i = 0; i < firstoddcnt.second;i++){
                ans.push_back(firstoddcnt.first);
                wordcnt[firstoddcnt.first]--;
        }
        for(auto it: wordcnt){
                for (int i = 0; i < it.second;i++){
                        if(i%2==0)
                                ans.push_back(it.first);
                        else
                                ans.push_front(it.first);
                }
        }

        for(auto it: ans){
                cout << it;
        }
        cout << endl;
}