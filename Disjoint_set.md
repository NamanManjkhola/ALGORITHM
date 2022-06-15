```cpp
#include <iostream>
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
        unionn(u,v);
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
