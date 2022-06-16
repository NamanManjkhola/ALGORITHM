#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no. of entries  :  " ;
    cin>>n;
    vector<pair<int,int>> data; // (weight,value)
    vector<pair<double,int>> valuebyweight; // (valuebyweight,index)
    
    for(int i=0; i<n; i++){
        int w,v;
        cin>>w>>v;
        data.push_back({w,v});
        valuebyweight.push_back({(double)v/w,i});
    }
    
    sort(valuebyweight.begin(), valuebyweight.end());
    
    int k;
    cin >> k;   //knapsack capacity
    double profit=0;
    for(auto it : valuebyweight){
        if(k==0){
            break;
        }
        if(data[it.second].first < k){
            k -= data[it.second].first;
            profit += data[it.second].second;
        } else{
            int x = data[it.second].first - k;
            k=0;
            profit += x*it.first;
        }
    }
    
    cout << profit << endl;

    return 0;
}
