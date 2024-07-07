#include<iostream>
using namespace std;

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
int div(long n){
    long ans=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans =i;
        }
    // return n;
    }
    if(ans==0){
        return -1;
    }
    else{

        return ans;
    }
}

int main() {
    
    // int a,b;
    long  x;
    // cout << "Enter the Values of a and b" << endl;
    // cin >> a >> b;

    cin>>x;
    // int ans = gcd(a,b);

    // cout << " The GCD of " << a << " & " << b << " is: " << ans << endl;
    long  ans= div(x);
    cout<<ans;

    return 0;
}