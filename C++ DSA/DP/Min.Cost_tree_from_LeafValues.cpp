#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

//rec
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right){
    //leaf node
    if(left == right){
        return 0;
    }

    int ans = INT_MAX;

    for(int i=left; i<right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
    }
    return ans;
}

//rec+mem
int solveMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp){
    //leaf node
    if(left == right){
        return 0;
    }
    if(dp[left][right] != -1){
        dp[left][right];
    }

    int ans = INT_MAX;

    for(int i=left; i<right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveMem(arr, maxi, left, i, dp) + solveMem(arr, maxi, i+1, right, dp));
    }
    return dp[left][right] = ans;
}
int mctFromLeafValues(vctor<int>& arr){
    map<pair<int, int>, int> maxi;

    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    for(int i=0; i,arr.size(); i++){
        maxi[{i,i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++){
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

    // //just for seeing
    // for(int i=0; i<arr.size(); i++){
    //     for(int j =0; j<arr.size(); j++){
    //         cout<<"for range"<<i<<"->"<<"max is"<<maxi[{i, j}]<<endl;
    //     }
    // }
    // return 0;

    // return solve(arr, maxi, 0, arr.size()-1);

    return solve(arr, maxi, 0, arr.size()-1, dp);

}
