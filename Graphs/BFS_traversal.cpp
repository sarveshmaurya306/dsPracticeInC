#include<bits/stdc++.h>
using namespace std;

void printBFS(int **edges, int n, int startingVertex){
    // pushing intial vertex to queue
    queue<int> q;
    bool *visitedArray = new bool[n];
    for (int i = 0; i < n;i++){
        visitedArray[i] = false;
    }

    q.push(startingVertex);
    visitedArray[startingVertex]=true;

    while(!q.empty()){
        int currentValue = q.front();
        q.pop();
        cout << currentValue << endl;

        for (int i = 0; i < n;i++){
            if(i==currentValue){
                continue;
            }
            if(edges[currentValue][i]==1 && !visitedArray[i]){
                q.push(i);
                visitedArray[i] = true;
            }
            //eges are pushed in queue;
            //now visited every edges present in queue one by one
        }
    }
    delete[] visitedArray;
}

int main() {
    int n, e;
    // n=total vertex
    // e=total edges
    cin >> n >> e;

    //making 2d array dynamically
    int **edges = new int *[n];
    for (int i = 0; i < n;i++){
        edges[i] = new int[n];
        //initializing with 0 means no edge initially;
        for (int j = 0; j < n;j++){
            edges[i][j] = 0;
        }
    }

    //taking input of two vertex which has edges
    for (int i = 0; i < e;i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //print aka BFS
    //method:= queue visited array;
    printBFS(edges, n, 0);

    //delete all the located memory
    for (int i = 0; i < n;i++){
        delete[] edges[i];
    }
    delete[] edges;
}
