#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    // for(int i=0; i<=30; i++){
    //     int ans = pow(2,i);   //bcoz max range is 2 ki power 31 minus 1 that is odd thatswahy we take max is 2 ki power 30
    //     if(ans==n){
    //         cout<<true<<endl;
    //     }
        
    // // }cout<< false;
    // }

    // code 2
    int ans = 1;
    for(int i =0; i<=30;){
        if(ans==0){
            return true;
        }
        ans = ans * 2;
    }
    return false;
}