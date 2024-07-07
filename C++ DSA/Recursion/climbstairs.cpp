int countDistinctWayToClimbStair(long long nStairs)
{
    //base case
    if(nStairs < 0)
        return 0;
    
    if(nStairs == 0)
        return 1;
    
    //R.C
    int ans = countDistinctWayToClimbStair(nStairs-1) 
        + countDistinctWayToClimbStair(nStairs-2);
    
    return ans;
}

// count ways to reach nth stairs
// explaination in copy

#include <bits/stdc++.h> 
#define MOD 100000007
// int countDistinctWays(int nStairs) {
//     if(nStairs < 0)
//         return 0;
    
//     if(nStairs == 0)
//         return 1;
    
//     //Recursion
//     int ans = countDistinctWays(nStairs-1) 
//         + countDistinctWays(nStairs-2);
    
//     return ans;
// }
// its que of dp that why tle 

int solve(long long nStairs, int i){
    //base case
    if(i==nStairs){
        return 1;
    }

    if(i>nStairs){
        return 0;
    }

    return (solve(nStairs, i+1) + solve(nStairs, i+2)) % MOD;
}

int countDistinctWays(long long nStairs){
    int ans = solve(nStairs, 0);
    return ans;
}
//abhi bhi tle aayega abhi dp use nhi ki h

