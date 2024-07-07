#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

//try kia th abut compllete  nhi hai ye





int gcd(int a, int b) {

    if(a==0)
    return b;

    if(b==0)
    return a;

    while(a != b) {

        if(a>b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
void div(int n){
    int ans=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans =i;
        }
    n= ans;
}
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    // int t;
    // cin>>t;
    // while(t--){
        int l;
        int r;
        int a,b;
        cin>>l>>r;
        if(l==r){            
            div(l);
            a=l;
            cout<<a;
            // if(a==0){
            //     cout<<-1<<endl;
            // }
            // else{

            //     b= l-a;
            //     if(gcd(a,b)==1){
            //         cout<<-1<<endl;
            //     }
            //     else{
            //         cout<<a<<" "<<b<<endl;
            //     }
            // }

        }
        else{
            a= r/2;
            b= ceil(r/2);
            if(gcd(a,b)==1){
                cout<<-1<<endl;
            }
            else{
                cout<<a<<" "<<b<<endl;
            }
        }
 
    // }
    return 0;
}