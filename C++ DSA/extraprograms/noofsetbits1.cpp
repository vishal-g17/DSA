#include<iostream>
using namespace std;

void fn(int m,int n){
    int ans=0;
    int bit1,bit2;
    while(n!=0){
        bit1 = n | 1;
        if(bit1==n){        
            ans++;
        }
        n=n>>1;
    }
    while(m!=0){
        bit2 = m | 1;
        if(bit2==m){        
            ans++;
        }
        m=m>>1;
    }
    cout<<ans;
}

int main(){
    int m,n;
    cin>>n>>m;
    fn(m,n);
}