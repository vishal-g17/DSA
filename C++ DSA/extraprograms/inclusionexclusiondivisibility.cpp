#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
int divisible(int n, int a , int b){
    int cnt1=n/a;
    int cnt2=n/b;
    int cnt3=n/(a*b);
    return cnt1+cnt2-cnt3;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<divisible(a,b,c);
   
}