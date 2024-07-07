#include<iostream>
using namespace std;
bool isprime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
        return true;
    }
}

void solve(){
    string s;
    cin>>s;
    bool f= false;
    int ans =0;
    for(int i=0;i<8;i++){
        string ss="";
        ss=s[i]+ss;
        for(int j=i+1;j<9;j++){
            string sk= ss+s[j];
            int n=0;
            for(char c : sk){
                n = n*10 + (c - '0');
            }
            if(isprime(n)){
                f=true;
                ans=n;
                break;
            }
        }

    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}