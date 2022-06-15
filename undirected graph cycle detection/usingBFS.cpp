//cycle detection in undirected graph using dfs
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<int> adj[], vector<int> &vis, int i){
    queue<pair<int,int>> q;
    vis[i] = 1;
    q.push({i,-1});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        //visit adjacent nodes
        for(auto it : adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push({it,node});
            }
            else if(it != par) return true;
        }
    }
    return false;
    
}

bool isCycle(vector<int> adj[], int v){
    vector<int> visited(v+1,0);
    for(int i=1; i<v+1; i++){
        if(visited[i]==0){
            if(detectCycle(adj,visited,i))  return true;
        }
    }
    return false;
}

int main()
{
    //creating adj list
    int v,e;
    cin >> v >> e;
    vector<int> adj[v+1];
    
    for(int i=0; i<e; i++){
        int a,b,wt;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    if(isCycle(adj,v)) cout << "Graph has a cycle" << endl;
    else cout << "Graph doesn't have a cycle" << endl;

    return 0;
}
