#include<bits/stdc++.h>
using namespace std;
 
#define ll long long  
#define vi vector<int>
#define vll vector<long long int>
 
ll minCost(ll arr[], ll n){
    priority_queue<ll, vector<ll>, greater< ll> > pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size()>1){
        ll first = pq.top();
        pq.pop();

        ll second = pq.top();
        pq.pop();

        ll mergedLength = first + second;
        cost += mergedLength;

        pq.push(mergedLength);
    }
    return cost;
}