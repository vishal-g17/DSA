#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q = n/3;
        int r = n %3;

        if(n== 10 || n== 11){
            cout<<"YES"<<endl;
            cout<<1<<" "<<2<< " "<<n-3<<endl; 
        }
        else if(q>3){
            cout<<"YES"<<endl;
            if(r==0){
                cout<<1<<" "<<4<<" "<<n-5<<endl;
            }
            else{
                cout<<1<<" "<<2<<" "<<n-3<<endl;
            }
        }
        else{
            if(n== 7 || n==8){
                cout<<"YES"<<endl;
                cout<<1<<" "<<2<<" " <<n-3<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }


    }
    return 0;
}