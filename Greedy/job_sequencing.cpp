//job sequencing
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter no. of jobs : ";
    cin >> n;
    vector<pair<int,int>> jobs;
    
    for(int i=1; i<=n; i++){
        int deadline, cost;
        cin>>deadline>>cost;
        jobs.push_back({cost,deadline});
    }
    vector<int> slot(n+1,-1);  //for alloting space to jobs
     
    sort(jobs.begin(), jobs.end());

    int profit=0;
    for(int i=n; i>=1; i--){
        int j = jobs[i].second;
        while(j--){
            if(slot[j]==-1){
                slot[j]=0;
                profit += jobs[i].first;
                break;
            }
        }
    } 
       
    cout<< "profit : " << profit << endl;

    return 0;
}
