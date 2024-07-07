#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int minDays(int S, int N, int M){
    int sunday = S/7;

    int buyingDays = S - sunday;
    int totalFood = S*M;
    int ans =0;

    if(totalFood % N == 0){
        ans = totalFood / N;
    }
    else{
        ans = totalFood / N + 1;
    }

    //sunday vala catch

    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;
    }
}