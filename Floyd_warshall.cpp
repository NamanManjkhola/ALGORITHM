#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int graph[5][5] = 
    { 
        {0,0,0,0,0},
        {0,0,3,INF,7},
        {0,8,0,2,INF},
        {0,5,INF,0,1},
        {0,2,INF,INF,0}
                   
    };
    
    //floyd warshall algorithm
    for(int k=1; k<5; k++){
        for(int i=1; i<5; i++){
            for(int j=1; j<5; j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    
    //result
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            if(graph[i][j]==INF){
                cout << "INF ";
            }else{
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
