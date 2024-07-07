#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
// int solveTab(vector<int>& prices){
//     int n = prices.size();
//     // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//     vector<vector<int>> curr(2, vector<int>(k+1, 0));
//     vector<vector<int>> next(2, vector<int>(k+1, 0));

//     for(int index =n-1; index >=0; index--){
//         for(int buy=0; buy <=1; buy++){
//             for(int limit=1; limit <=k; limit++){
//                 int profit = 0;
//                 if(buy){
//                     int buykro = -prices[index] + next[0][limit];
//                     int skipkro = 0 + next[1][limit];
//                     profit = max(buykro, skipkro);
//                 }
//                 else{
//                     int sellkro = prices[index] + next[1][limit-1];
//                     int skipkro = 0+ next[0][limit];
//                     profit = max(sellkro, skipkro);
//                 }
//                 curr[buy][limit] = profit; ;
//             }
//         }
//         next = curr;
//     }
//     return next[1][k];
// }

// int maxProfit(vector<int>& prices){
//     return solveTab(prices);
// }

//new approach

//rec only
int solve(int index, int operationNo, int k, vector<int>& prices){
    if(index == prices.size()){
        return 0;
    }
    if(operationNo == 2*k){
        return 0;
    }
    int profit ==0;
    if(operationNo%2 == 0){
        //buy allowed
        int buykro = -prices[index] + solve(index+1, operationNo+1, k, prices);
        int skipkro = 0+ solve(index+1, operationNo, k, prices);
        profit = max(buykro, skipkro);
    }
    else{
        int sellkro = prices[index] + solve(index+1, operationNo +1, k, prices);
        int skipkro = 0+ solve(index+1, operationNo, k, prices);
        profit = max(sellkro, skipkro);
    }
    return profit;
}

//memoizTION
int solveMem(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>>& dp){
    if(index == prices.size()){
        return 0;
    }
    if(operationNo == 2*k){
        return 0;
    }

    if(dp[index][operationNo] != -1){
        return dp[index][operationNo];
    }

    int profit ==0;
    if(operationNo%2 == 0){
        //buy allowed
        int buykro = -prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
        int skipkro = 0+ solveMem(index+1, operationNo, k, prices, dp);
        profit = max(buykro, skipkro);
    }
    else{
        int sellkro = prices[index] + solveMem(index+1, operationNo +1, k, prices, dp);
        int skipkro = 0+ solveMem(index+1, operationNo, k, prices, dp);
        profit = max(sellkro, skipkro);
    }
    return dp[index][operationNo] = profit;
}

//tab
// int solveTab(int k, vector<int>& prices){
//     int n = prices.size();
//     vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
    
//     for(int index= n-1; index >=0; index--){
//         for(int operationNo=0; operationNo < 2*k; operationNo++){
//             int profit ==0;
//             if(operationNo%2 == 0){
//                 //buy allowed
//                 int buykro = -prices[index] + dp[index+1][operationNo+1];
//                 int skipkro = 0+ dp[index+1][operationNo];
//                 profit = max(buykro, skipkro);
//             }
//             else{
//                 int sellkro = prices[index] + dp[index+1][operationNo +1];
//                 int skipkro = 0+ dp[index+1][operationNo];
//                 profit = max(sellkro, skipkro);
//             }
//             dp[index][operationNo] = profit;
//         }
//     }
//     return dp[0][0];
// }

//space opt
int solveTab(int k, vector<int>& prices){
    int n = prices.size();

    vector<int> curr(2*k+1 , 0);
    vector<int> next(2*k+1 , 0);
    
    for(int index= n-1; index >=0; index--){
        for(int operationNo=0; operationNo < 2*k; operationNo++){
            int profit ==0;
            if(operationNo%2 == 0){
                //buy allowed
                int buykro = -prices[index] + next[operationNo+1];
                int skipkro = 0+ next[operationNo];
                profit = max(buykro, skipkro);
            }
            else{
                int sellkro = prices[index] + next[operationNo +1];
                int skipkro = 0+ next[operationNo];
                profit = max(sellkro, skipkro);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next;[0];
}


int maxProfit(int k, vector<int>& prices){
    // return solve(0, 0, k, prices);

    // int n= prices.size();
    // vector<vector<int>> dp(n, vector<int> (2*k, -1));
    // return solveMem(0, 0,k, prices, dp);

    return solvetab(k, prices);
}