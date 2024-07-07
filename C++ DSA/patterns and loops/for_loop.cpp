#include<iostream>
using namespace std;
int main (){
   int n;
   cin>>n;


//    int sum=0;
//    for(int i = 1; i<=n;i++){
//     sum = sum +i;
//    }
//    cout<<sum;

// code 2 for fibonacci series
    int a =0,b=1;
    cout<<a<<" "<<b<<" ";
    for(int i =1;i<=n;i++){
        int nextNo = a+b;
        cout<<nextNo<<" ";
        a= b;    
        b = nextNo;
    }
}