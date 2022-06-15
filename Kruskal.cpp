#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int parent[100000];
int rankk[100000];

void make_set(int n){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

int find_parent(int i){
    if(parent[i] == i){
        return i;
    }
    return parent[i] = find_parent(parent[i]);
}

void unionn(int u, int v){
    u = find_parent(u);
    v = find_parent(v);
    
    if(rankk[u] < rankk[v]){
        parent[u] = v;
        rankk[v]++;
    }
    else if(rankk[u] > rankk[v]){
        parent[v] = u;
        rankk[u]++;
    }
    else{
        parent[v] = u;
        rankk[u]++;
    }
}


int main()
{
    int n; 
    cout << "enter no. of edges : ";
    cin >> n;
    vector<vector<int>> edges;
    
    for(int i=0; i<n; i++){
        int wt,u,v;
        cin >> u>>v>>wt;
        edges.push_back({wt,u,v});
    }
    
    //sort acc. to weight
    sort(edges.begin(), edges.end());
    
    //create a set
    make_set(n);
    int cost = 0;
    for(auto i : edges){
        int wt = i[0];
        int u = i[1];
        int v = i[2];
        int a = find_parent(u);
        int b = find_parent(v);
        if(a == b){
            continue;
        } else{
            cout << u << " " << v << endl;
            unionn(u,v);
            cost += wt;
            
        }
        
    }
    cout << "COST = " <<cost;
    

    return 0;
}
