#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
    //    int j=1;also use j=i to form no trianle
    
        int j=i;
       while(j<=n){
        cout<<i;
        j++;
       } 
       cout<<endl;
       i++;
    }
}