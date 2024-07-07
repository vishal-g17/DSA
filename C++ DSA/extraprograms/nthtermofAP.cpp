#include<iostream>
using namespace std;

int nthterm(int n){
    return 3*n + 7;
}

int main(){
    cout<< "Enter n : ";
    int n;
    cin>>n;
    cout<<n<<"th term of AP is : "<<nthterm(n);
    }