#include<bits/stdc++.h>
#include <cmath>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    int t;
    cin>>t;
    while(t--){
        int a, b,c;
        double x,res;
        int cnt=0;
        cin>>a>>b>>c;
        if(a==b){
            cout<<cnt<<endl;
        }
        else{
            if(a>b){
                x=a-b;
                x=x/ (2*c);
                cout<<ceil(x)<<endl;
            }    
            else if(b>a){
                x=b-a;
                x=x/ (2*c);
                cout<<ceil(x)<<endl;
            }

        }
    }
    return 0;
}