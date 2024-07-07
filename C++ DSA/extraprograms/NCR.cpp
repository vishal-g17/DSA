#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

// ncr nikalne k liye jruri nhi sbka fact nikalke kre 
// jaise 10C3 hai ab 10 ko reduce krte jao jitna r hai mtlb 3 place tk hi reduce hoga like 10 9 8 and for denominator start from 1 to r like 1 2 3 
// ye isliye kia hai kyuki no of r elements k baad niche uper smae hota hai
 
long long ncr(int n, int r){
    long long res =1;
    for(int i=0; i<r; i++){
        res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}