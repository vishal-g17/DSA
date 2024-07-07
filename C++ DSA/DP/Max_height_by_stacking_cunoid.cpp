bool check(vector<int> base, vector<int> newBox){
    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
        return true;
    }
    else{
        return false;
    }
}

int solveTab(int n, vector<vector<int>>&a){
    
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr= n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=0; prev--){
            //include
            int take =0;
            if(prev == -1 || check(a[curr] > a[prev])){
                take =a[curr][2] + nextRow[curr+1];
            }

            //exclude
            int nottake =0 + nextRow[prev +1];

            nextRow[prev+1] = max(take, nottake);
        }
        nextRow = currRow;
    }
    return nextRow[ -1 +1];//=1 bcoz it give invalid index at -1
}

int maxHeight(vector<vector<int>>& cuboids){
    //step 1 sort all dimensions of every cuboid
    for(auto &a : cuboids){
        sort(a.begin(), a.end());
    }

    //step 2 sort all cuboids basis on width or lenght
    sort(cuboids.begin(), cuboids.end());

    //step 3 logic of LIS
    return solveTab(suboids.size(), cuboids);

}