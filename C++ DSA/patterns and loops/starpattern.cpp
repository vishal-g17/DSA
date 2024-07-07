#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    // code 1
    // int row =1;
    // while(row<=n){
    //     int col =1;
    //     while(col<=row){
    //         cout<<"*";
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }


    // code 2
    int row = 1;
    while(row<=n){
        int col=1;
        while(col<=n){
            char ch ='A'+row+col-2;
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
}