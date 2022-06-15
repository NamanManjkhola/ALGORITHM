```cpp
#include <iostream>
using namespace std;


int parent[100000];
int rank[100000];

void make_set(int n){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(int i){
    if(parent[i] == i){
        return i;
    }
    return parent[i] = find_parent(parent[i]);
}

void union(int u, int v){
    u = find_parent(u);
    v = find_parent(v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
        rank[u]++;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}


int main()
{
    int n; 
    cout << "enter no. of vertices : ";
    cin >> n;
    //create a set
    make_set(n);
    
    //perform union operation m times
    int m;
    cout << "enter no. of operations : ";
    cin >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        union(u,v);
    } 
    
    //check if 2 and 3 have same parent
    if(parent[2] == parent[3]){
        cout << "same";
    } else{
        cout << "no";
    }

    return 0;
}

```
