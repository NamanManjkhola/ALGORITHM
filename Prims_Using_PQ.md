```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //creating graph
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    
    for(int i=0; i<e; i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    
    vector<int> parent(v,-1),key(v,INT_MAX);
    vector<bool> mstset(v,false);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    key[0] = 0;
    mstset[0] =true;
    pq.push({0,0});
    
    
    for(int i=0; i<v-1; i++){
        int u = pq.top().second;
        pq.pop();
        mstset[u] = true;
            
        for(auto k : adj[u]){
            int weight = k.second;
            int node = k.first;
            if(mstset[node]==false && key[node]>weight){
                parent[node] = u, key[node] = weight, pq.push({key[node], node});
            }
        }
    }
    for(int i=1; i<v; i++){
        cout << parent[i] << "---" << i << endl;
    }
    
    return 0;
}
```
