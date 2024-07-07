#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    // code 1 decimal to binary
    int ans =0;
    int i=0;
    while(n!=0){
        int bit = n & 1;
        cout<<bit<<" ";
        // ans = ((bit * pow(10, i)) + ans);  //use this formula for reversing 
        
        // ans = (10* ans) + bit; //use for same order
        n = n >> 1;
        i++;
    }
    cout<<"Answer is "<<ans<<endl;
    // ans of 5 is 101 and code is correct but this code give ans 100

    
    //left shift 2 se multiply krta h and right shift divide
    //kisi no ka 1 se bitwis and lene pr 1 aaye to odd nhi to 0 mtlb even

// code 2 binary to decimal
    // int i=0,ans=0;
    //     while(n!=0){
    //         int digit =n%10;
    //         if(digit==1){
    //             ans = ans + pow(2,i);
    //         }
    //         n= n /10;
    //         i++;
    //     }
    //     cout<<ans<<endl;
}


