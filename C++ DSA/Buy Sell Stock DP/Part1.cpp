#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int maxProfit(vector<int>& prices){
    int mini= prices[0];
    int profit =0;
    for(int i=1; i<prices.size(); i++){
        int diff = prices[i] -mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }
    return profit;
}

//agr hm ith day pr sell krte hai to hmne buy kia hoga 1 to i-1 day k bich me 