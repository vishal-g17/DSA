//only recursion
int solve(vector<int>& obstacles, int currlane, int currpos){
    //base case
    int n = obstacles.size();
    if(currpos == n){
        return 0;
    }
    if(obstacles[currpos + 1] != currlane){
        return solve(obstacles, currlane, currpos+1);
    }
    else{
        //sidejump
        int ans = INT_MAX;
        for(int i =1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, 1 + solve(obstacles, i, currpos));
            }
            return ans;
        }
    }
}

//rec + mem
int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp){
    //base case
    int n = obstacles.size();
    if(currpos == n){
        return 0;
    }
    if(obstacles[currpos + 1] != currlane){
        return solveMem(obstacles, currlane, currpos+1, dp);
    }
    if(dp[currlane][currpos] != -1){
        return dp[currlane][currpos];
    }

    else{
        //sidejump
        int ans = INT_MAX;
        for(int i =1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

//tabulation isme thoda flow change hoga answer nikalne ka pehle vale se
//isme hm shayad target se imitial pos tk aayenge
int solvetab(vector<int>& obstacles){
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));

    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;
    dp[4][n] = 0;

    for(int currpos = n-1; currpos>= 0 ; currpos--){
        for(int currlane = 1; currlane <=3; currlane++){
            if(obstacles[currpos + 1] != currlane){
                dp[currlane][currpos]= dp[currlane][currpos+1];
            }
            else{
                //sidejump
                int ans = 1e9;
                for(int i =1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i){
                        ans = min(ans, 1 + dp[i][currpos+1]);
                        //hme ye currpoa me 1 add isliye kiya hai video dekho dobara
                    }
                }
                dp[currlane][currpos] =  ans;
            }

        }
    }
    return min(dp[2][0] , min(1+dp[1][0], 1+dp[3][0]));
}

//space opt
int solvetab(vector<int>& obstacles){
    int n = obstacles.size();

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currpos = n-1; currpos>= 0 ; currpos--){
        for(int currlane = 1; currlane <=3; currlane++){
            if(obstacles[currpos + 1] != currlane){
                curr[currlane]= next[currlane];
            }
            else{
                //sidejump
                int ans = 1e9;
                for(int i =1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i){
                        ans = min(ans, 1 + next[i]);
                        //hme ye currpoa me 1 add isliye kiya hai video dekho dobara
                    }
                }
                curr[currlane] =  ans;
            }

        }
        next = curr;
    }
    return min(next[2] , min(1+next[1], 1+next[3]));
}



int minSidejump(vector<int>& obstacles){
    // return solve(obstacles,2.0);

    // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));//4 means 3 lanes and size n+1
    // solveMem(obstacles,2,0,dp);

    return solveTab(obstacles);
}