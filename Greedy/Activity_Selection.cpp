//activity selection problem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter no. of activities : ";
    cin>>n;
    vector<pair<int,int>> act;
    
    //input activities
    for(int i=0; i<n; i++){
        int st,en;
        cin >>st >> en;
        act.push_back({en,st});
    }
    
    
    sort(act.begin(), act.end());
    int noOfAct = 1;
    int prevEnd = act[0].first;
    
    for(int i=1; i<n; i++){
        if(prevEnd <= act[i].second){
            noOfAct++;
            prevEnd = act[i].first;
        }
    }
    cout << "max activity performed : " << noOfAct;
    
    
    return 0;
}
