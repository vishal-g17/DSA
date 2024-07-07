#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
void solve(){
    int x,y,n;
    cin>>x>>y>>n;
    vector<int> v;
    int count=1;
    for(int i=0;i<n;i++){
        v.push_back(y);
        y-=count;
        count++;
    }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    if(v[v.size()-1]<x){
        cout<<-1<<endl;
    }
    else{
        cout<<x<<" ";
        for(int i=v.size()-2;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    }
 
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();

    }
    return 0;
}