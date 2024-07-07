#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = 0;
    int INT_MAX = (pow(2,31) - 1);//
    int INT_MIN = pow(2,31);//these are exception cases when ans is getting out of range
    while(n!=0){
        int digit = n % 10;
        if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
            return 0;
        }
        ans = (ans *10) + digit;
        n= n/10;   
    }
    cout<<ans;

    //this code is not valid for out of range answer like 2 ki power minus 31(int minimum) to 2 ki power 31 minus 1(int maximum)


}