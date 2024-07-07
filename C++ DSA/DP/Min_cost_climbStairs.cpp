#include<bits/stdc++.h>
using namespace std;
class solution{
public:
int solve(vector<int> &cost, int n){
    //base case
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    //step 3
    dp[n] =cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return dp[n];
}


int solve2(vector<int> &cost, int n, vector<int> &dp){
    //base case
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }

//step 2
    if(dp[n] != -1){
        return dp[n];
    }

    //step 2
    dp[n] = cost[n] + min(solve2(cost, n-1,dp), solve2(cost, n-2, dp));
    return dp[n];
}

//solve 3 for tabulation

int solve3(vector<int> &cost, int n){
    //step 1
    vector<int> dp(n+1);
    //step 2
    dp[0]= cost[0];
    dp[1]= cost[1];

    //3rd step
    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

//solve 4 for Space optimization
int solve4(vector<int> &cost, int n){
   
    int prev2= cost[0];
    int prev1 =cost[1];

    //3rd step
    for(int i=2;i<n;i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1= curr;
    }
    return min(prev1, prev2);
}
};

int mincostClimbStairs(vector<int> &cost){
    // int n= cost.size();
    // //it can be simplifies more -? Homweork
    // int ans = min((cost, n-1), solve(cost, n-1));
    // return ans;

    // int n = cost.size();
    // //step 1
    // vector<int> dp(n+1);
    // int ans = min(solve(cost, n-1, dp), solve2(cost, n-2, dp));
    // return ans;

    // int n= cost.size();
    // return solve3(cost,n);

    int n= cost.size();
    return solve4(cost,n);


}
