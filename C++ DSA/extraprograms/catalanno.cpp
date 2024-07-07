#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

int catalan(int n){
    int ans=0;
    if(n<=1){
        return 1;
    }
    for(int i=0;i<=n-1;i++){
        ans += catalan(i)*catalan(n-i-1);
    }
        return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<10;i++){
        cout<<catalan(i)<<" ";
    }
    cout<<endl;
 
}