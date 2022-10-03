#include <bits/stdc++.h> 

void heapify(vector<int> &pq, int ind){
    int par= ind/2;
    if(par==0) return;
    if(pq[par] > pq[ind]) {
        swap(pq[par], pq[ind]);
        heapify(pq, par);
    }
}

void remove(vector<int> &pq, int ind){
    int left= 2*ind, right= 2*ind+1;
    if(pq[ind] > pq[left]) {
        swap(pq[ind], pq[left]);
        remove(pq, left);
    } 
    if(pq[ind] > pq[right]){
        swap(pq[ind], pq[right])        ;
        remove(pq, right);
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> pq(1e6, INT_MAX);
    vector<int> ans;
    int cnt=0;
    
    for(int i=0;i<n;i++){
        int check= q[i][0];
        if(check==0){ //add element to the heap
            cnt++;
            int value= q[i][1];
            pq[cnt]=value;
            heapify(pq, cnt);
        } else if(check==1) { //print minimum and delete it from heap
            ans.push_back(pq[1]);
            swap(pq[1], pq[cnt]);
            pq[cnt]=INT_MAX;
            cnt--;
            remove(pq, 1);
        }
    }
    return ans;
}
