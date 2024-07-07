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
        string a;
        cin>>a;
        string b;
        cin>>b;
        int size = a.length();
        bool flag = false;
        for(int i=0 ; i< size-1; i++){
            if(a[i]=='0' and b[i]=='0' and a[i+1]=='1' and b[i+1]=='1'){
                flag=true;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}