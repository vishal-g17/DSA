#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
vector<int> CandyStore (int candies[], int N, int k){
    sort(candies, candies+N);

    int mini =0;
    int buy =0;
    int free =0;
    
//for mini
    while(buy <= free){
        mini = mini + candies[buy];
        buy++;
        free = free - k;
    }

    int maxi =0;
    buy = N-1;
    free =0;

//for maxi
    while(free <= buy){
        maxi = maxi + candies[buy];
        buy--;
        free = free +k;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}