int LongestSubsequence(vector<int>& arr, int diff){

    unordered_map<int, int>dp;
    int ans = 0;

    for(int i=0; i<arr.size(); i++){
        int temp = arr[i] - diff;
        int tempAns= 0;
    
        //check answer exists for temp already or not
        if(dp.count(temp)){
            tempAns = dp[temp];
        }
        //current answer update
        dp[arr[i]] = 1 + tempAns;

        //ans update
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}