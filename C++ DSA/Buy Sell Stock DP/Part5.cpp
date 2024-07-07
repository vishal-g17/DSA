#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
//saare same soln hoge part two vale bs optimisedvala hai yh apr

//space opt
int solveTab(vector<int>& prices, int fee){
    int n = prices.size();

    vector<int> curr(2,0);
    vector<int> next(2,0);

    for(int index =n-1; index >= 0; index--){
        for(int buy =0; buy <= 1; buy++){
            int profit = 0;
            if(buy){
                int buykro = -prices[index] + next[0];
                int skipkro = 0 + next[1];
                profit = max(buykro, skipkro);
            }
            else{
                int sellkro = prices[index] + next[1] - fee;
                int skipkro = 0+ next[0];
                profit = max(sellkro, skipkro);
            }
            curr[buy] =  profit;
        }
        next = curr;
    }
    return next[1];
}

//we can give fee at buy time also
//but dhyan rkhna ek transacrion me ke baar hi feee deni h

int maxProfit(vector<int>& prices, int fee){
    return solveTab(prices, fee);
}