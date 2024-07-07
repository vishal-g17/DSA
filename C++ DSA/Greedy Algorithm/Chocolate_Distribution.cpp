#include<bits/stdc++.h>
using namespace std;
 
#define ll long long  
#define vi vector<int>
#define vll vector<long long int>

ll findMinDiff(vector< ll> a, ll n, ll m){
    sort(a.begin(), a.end());
    int i=0;
    int j = m-1;

    int mini = INT_MAX;
    while(j < a.size()){
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}