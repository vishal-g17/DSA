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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt +=arr[i];
        }
        if(cnt %2 ==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}