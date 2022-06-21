// 0/1 knapsack
// recurrsive approach written in notebook
// bottom up approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int  n, int k){
    int i,j;
    int sol[n+1][k+1];
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<k+1; j++){
            if(i==0 || j==0){
                sol[i][j] = 0;
            }
            else if(wt[i-1]>j){
                sol[i][j] = sol[i-1][j];
            }
            else{
                sol[i][j] = max(sol[i-1][j], val[i-1] + sol[i-1][j-wt[i-1]]);
            }
        }
    }
    return sol[n][k];
}

int main()
{
    int wt[] = {20,10,50,2};
    int val[] = {100,300,500,40};
    
    cout << knapsack(wt,val,4,50)<<endl;

    return 0;
}
