#include<bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int startingVertex, bool* visited){
    cout << startingVertex << endl;
    visited[startingVertex]=true;

    for (int i = 0; i < n;i++){
        //for self loop
        if(i==startingVertex){
            continue;
        }
        //if there is edge between vertext then
        if(edges[startingVertex][i]==1){
            //if we have already visited it
            if(visited[i]){
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    // n=total vertex
    // e=total edges

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

    bool *visitedArray = new bool[n];
    for (int i = 0; i < n;i++){
        visitedArray[i] = false;
    }
    //print aka DFS
    print(edges, n, 0, visitedArray);


    //delete all the located memory
    for (int i = 0; i < n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visitedArray;
}