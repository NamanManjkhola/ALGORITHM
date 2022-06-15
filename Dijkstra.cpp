#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //creating adj list
    int v,e,source;
    cin >> v >> e;
    vector<pair<int,int>> adj[v+1];
    
    for(int i=0; i<e; i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    
    cin >> source;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(v+1,INT_MAX);
    
    //distance from 1-1
    distance[1] = 0;
    //(wt,node)
    pq.push({0,1});
    
    
    while(!pq.empty()){
        //pq values
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        
        //iterate to adjacent nodes
        for(auto i : adj[prev]){
            int next = i.first;
            int nextDist = i.second;
            
            //if short path found omit into distance[] 
            //also, add into pq the adjacent wt and node
            if(distance[next]>dist+nextDist){
                distance[next] = distance[prev] + nextDist;
                pq.push({distance[next], next});
            }
        }
    }
    
    for(int i=1; i<v+1; i++){
        cout << "1-"<<i<<"  --> " << distance[i] <<endl;
    }

    return 0;
}
